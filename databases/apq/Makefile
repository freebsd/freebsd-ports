# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	apq
PORTVERSION=	${APQ_VERSION}
PORTREVISION=	${BASE_PORTREV}
CATEGORIES=	databases
MASTER_SITES=	LOCAL/marino

MAINTAINER=	marino@FreeBSD.org
COMMENT=	APQ Ada95 database base library

LICENSE=	GPLv2 GMGPL
LICENSE_COMB=	multi

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		gprbuild:${PORTSDIR}/devel/gprbuild

USES=		ada tar:bzip2
PORTDOCS=	README HISTORY
HAS_CONFIGURE=	yes
WRKPATH=	${WRKDIR}/build
CONFIGURE_ARGS= --prefix=${PREFIX} \
		--disable-relocatable \
		--work-path=${WRKPATH} \
		--processors=${MAKE_JOBS_NUMBER}

OPTIONS_DEFINE=	DOCS

.include "${.CURDIR}/Makefile.version"
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/for Object_Dir/d' ${WRKSRC}/gnat/apq.gpr.in

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/gnat \
		${STAGEDIR}${PREFIX}/lib/apq/static \
		${STAGEDIR}${PREFIX}/include/apq \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKPATH}/include/apq/* \
		${STAGEDIR}${PREFIX}/include/apq
	${INSTALL_DATA} ${WRKPATH}/lib/apq/static/*.a* \
		${STAGEDIR}${PREFIX}/lib/apq/static
	${INSTALL_DATA} ${WRKPATH}/lib/gnat/apq.gpr \
		${STAGEDIR}${PREFIX}/lib/gnat
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/HISTORY \
		${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
