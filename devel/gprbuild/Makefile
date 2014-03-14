# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gprbuild
PORTVERSION=	${SNAPSHOT}
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/
DISTNAME=	gprbuild-gpl-${YEAR}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Adacore multi-language software build tool

LICENSE=	GPLv3

BUILD_DEPENDS+=	xmlada>=3.2:${PORTSDIR}/textproc/xmlada \
		gnat_util>=2013:${PORTSDIR}/lang/gnat_util

WRKSRC=		${WRKDIR}/gprbuild-${YEAR}-src
YEAR=		2013
SNAPSHOT=	20130416
GNU_CONFIGURE=	yes
USES=		ada gmake
CONFIGURE_ARGS+=BUILD=production
CONFIGURE_ARGS+=PROCESSORS=${MAKE_JOBS_NUMBER}
PORTDOCS=	html txt pdf info
PORTEXAMPLES=	.

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

do-build:
#	Recreate the do-build target without -j parameter
#	It interferes with PROCESSORS configure argument
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET})

post-patch:
	@${REINPLACE_CMD} -e "s,@AUXPREFIX@,${PREFIX}/gcc-aux," \
	  ${WRKSRC}/share/gprconfig/compilers.xml

post-install:
.if !${PORT_OPTIONS:MDOCS}
	${RM} -rf ${STAGEDIR}${DOCSDIR}
.endif
.if !${PORT_OPTIONS:MEXAMPLES}
	${RM} -rf ${STAGEDIR}${EXAMPLESDIR}
.endif
	cd ${STAGEDIR}${PREFIX}; ${FIND} share/examples -type d -empty | \
	  ${SORT} -dr | ${XARGS} ${RMDIR}

.include <bsd.port.mk>
