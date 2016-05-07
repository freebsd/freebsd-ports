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

BUILD_DEPENDS=	bash:shells/bash \
		gprbuild:devel/gprbuild

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

post-patch:
	@${REINPLACE_CMD} -e '/for Object_Dir/d' ${WRKSRC}/gnat/apq.gpr.in
	${REINPLACE_CMD} -e 's|processors=2|gprbuild_params="--autoconf=apq.cgpr"|' \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|-ws|-ws --autoconf=dummy.cgpr|' \
		${WRKSRC}/scripts/buildutil.sh

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

do-install-DOCS-on:
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/HISTORY \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
