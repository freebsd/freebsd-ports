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
DESTINY=	${WRKDIR}/destino
BUILD_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	build

do-install:
	# To support DESTDIR in the future, install twice
	${MKDIR} ${DESTINY}${PREFIX}/bin
	${MKDIR} ${DESTINY}${PREFIX}/share/gps/plug-ins
	${MKDIR} ${DESTINY}${PREFIX}/share/doc/gps/html
	${MKDIR} ${DESTINY}${PREFIX}/share/doc/adacontrol
	${MKDIR} ${DESTINY}${PREFIX}/share/gprconfig
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/adactl ${BUILD_WRKSRC}/pfni \
		${BUILD_WRKSRC}/ptree ${DESTINY}/${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/GPS/adacontrol.xml \
		${DESTINY}${PREFIX}/share/gprconfig
	${INSTALL_DATA} ${WRKSRC}/GPS/*adactl* ${WRKSRC}/GPS/pfni.* \
		${DESTINY}${PREFIX}/share/gps/plug-ins
	${INSTALL_MAN} ${WRKSRC}/doc/*.html \
		${DESTINY}${PREFIX}/share/doc/gps/html
	${INSTALL_MAN} ${WRKSRC}/doc/*.pdf ${WRKSRC}/doc/*.html \
		${DESTINY}${PREFIX}/share/doc/adacontrol
	# Now install from DESTDIR
	${CP} -pR ${DESTINY}${PREFIX}/ ${PREFIX}/

.include <bsd.port.mk>
