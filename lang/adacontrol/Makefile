# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	adacontrol
PORTVERSION=	1.15r5
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	SF/adacontrol
DISTNAME=	adactl-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Tool for detecting use or non-use of specific Ada constructs

LICENSE=	GPLv2 GMGPL
LICENSE_COMB=	multi

BUILD_DEPENDS=	asis>=2011:${PORTSDIR}/lang/asis

USES=		ada
WRKSRC=		${WRKDIR}/adactl-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	build
PORTDOCS=	adacontrol*

OPTIONS_DEFINE= DOCS

.include <bsd.port.options.mk>

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
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${WRKSRC}/doc/*.html \
		${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
