# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	adacontrol
PORTVERSION=	1.18r9
CATEGORIES=	lang
MASTER_SITES=	SF/adacontrol
DISTNAME=	adactl-${PORTVERSION}-src

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Tool for detecting use or non-use of specific Ada constructs

LICENSE=	GPLv2 GMGPL
LICENSE_COMB=	multi

BUILD_DEPENDS=	asis>=2013:lang/asis

USES=		ada tar:tgz
WRKSRC=		${WRKDIR}/adactl-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	build
PORTDOCS=	adacontrol*

OPTIONS_DEFINE= DOCS PROJECTS

PROJECTS_DESC=		Support the direct processing of .gpr files
PROJECTS_BUILD_DEPENDS=	gprbuild:devel/gprbuild \
			${LOCALBASE}/lib/gnat/gnatcoll.gpr:devel/gnatcoll

do-patch-PROJECTS-off:
	(cd ${WRKSRC}/src && ${MV} \
		implementation_options-i_options_from_gpr_project.adb \
		implementation_options-i_options_from_gpr_project_gpr.adb)
	(cd ${WRKSRC}/src && ${MV} \
		implementation_options-i_options_from_gpr_project_nogpr.adb \
		implementation_options-i_options_from_gpr_project.adb)
	${REINPLACE_CMD} -e '/gnatcoll/d' ${WRKSRC}/build.gpr

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gnatmake -Pbuild)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin \
		${STAGEDIR}${PREFIX}/share/gps/plug-ins \
		${STAGEDIR}${PREFIX}/share/doc/gps/html \
		${STAGEDIR}${PREFIX}/share/gprconfig
	${INSTALL_PROGRAM} ${WRKSRC}/adactl ${WRKSRC}/pfni \
		${WRKSRC}/ptree ${STAGEDIR}/${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/GPS/adacontrol.xml \
		${STAGEDIR}${PREFIX}/share/gprconfig
	${INSTALL_DATA} ${WRKSRC}/GPS/*adactl* ${WRKSRC}/GPS/pfni.* \
		${STAGEDIR}${PREFIX}/share/gps/plug-ins
	${INSTALL_DATA} ${WRKSRC}/doc/*.html \
		${STAGEDIR}${PREFIX}/share/doc/gps/html

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${WRKSRC}/doc/*.html \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
