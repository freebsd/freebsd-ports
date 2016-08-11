# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	adacontrol
PORTVERSION=	1.17r3
PORTREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	SF/adacontrol
DISTNAME=	adactl-${PORTVERSION}-src
DIST_SUBDIR=	adacontrol-01

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

OPTIONS_DEFINE= DOCS

do-build:
	(cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} gnatmake -Pbuild)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin \
		${STAGEDIR}${PREFIX}/share/gps/plug-ins \
		${STAGEDIR}${PREFIX}/share/doc/gps/html \
		${STAGEDIR}${PREFIX}/share/gprconfig
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/adactl ${BUILD_WRKSRC}/pfni \
		${BUILD_WRKSRC}/ptree ${STAGEDIR}/${PREFIX}/bin
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
