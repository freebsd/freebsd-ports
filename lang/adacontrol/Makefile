# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	adacontrol
PORTVERSION=	1.15r5
CATEGORIES=	lang
MASTER_SITES=	SF/adacontrol
DISTNAME=	adactl_old-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Tool for detecting use or non-use of specific Ada constructs

BUILD_DEPENDS=	asis>=2011:${PORTSDIR}/lang/asis \
		gnat_util>=2013:${PORTSDIR}/lang/gnat_util

USES=		ada gmake
WRKSRC=		${WRKDIR}/adactl-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	build

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/share/gps/plug-ins
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/gps/html
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/adacontrol
	${MKDIR} ${STAGEDIR}${PREFIX}/share/gprconfig
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/adactl ${BUILD_WRKSRC}/pfni \
		${BUILD_WRKSRC}/ptree ${STAGEDIR}/${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/GPS/adacontrol.xml \
		${STAGEDIR}${PREFIX}/share/gprconfig
	${INSTALL_DATA} ${WRKSRC}/GPS/*adactl* ${WRKSRC}/GPS/pfni.* \
		${STAGEDIR}${PREFIX}/share/gps/plug-ins
	${INSTALL_MAN} ${WRKSRC}/doc/*.html \
		${STAGEDIR}${PREFIX}/share/doc/gps/html
	${INSTALL_MAN} ${WRKSRC}/doc/*.pdf ${WRKSRC}/doc/*.html \
		${STAGEDIR}${PREFIX}/share/doc/adacontrol

.include <bsd.port.mk>
