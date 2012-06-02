# New ports collection makefile for:	qt40
# Date created:				Wed Jun 29 11:49:42 CEST 2005
# Whom:					lofi@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	assistant
PORTVERSION=	4.6.3
CATEGORIES?=	devel
MASTER_SITES=	${MASTER_SITE_QT}
PKGNAMEPREFIX=	qt4-
PKGNAMESUFFIX=	-adp
DISTNAME=	qt-assistant-qassistantclient-library-compat-src-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt documentation browser, adp compat version

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build corelib \
		gui network xml doc dbus
MAKE_JOBS_SAFE=	yes

ALL_TARGET=	first

WRKSRC=		${WRKDIR}/${DISTNAME:C/src/version/}

PLIST_FILES=	bin/assistant_adp

pre-configure:
	${REINPLACE_CMD} -e 's|$$$$\[QT_INSTALL_BINS]|${PREFIX}/bin|g' \
		${WRKSRC}/compat.pro

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -spec ${QMAKESPEC} QT_CONFIG+="dbus" \
		QT_PRODUCT="OpenSource" ${QMAKEFLAGS}

.include <bsd.port.mk>
