# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quassel
PORTVERSION=	0.12.4
PORTREVISION=	2
CATEGORIES=	irc
MASTER_SITES=	http://www.quassel-irc.org/pub/

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT?=	Qt 5 based distributed IRC client (client only or monolithic binary)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:outsource compiler:c++11-lib cpe execinfo pkgconfig tar:bzip2

CPE_VENDOR=	quassel-irc
CPE_PRODUCT=	quassel_irc

.if !defined(MASTERDIR)

LIB_DEPENDS=	libdbusmenu-qt5.so:devel/libdbusmenu-qt5
USE_QT5=	buildtools_build core dbus gui network phonon4 qmake_build webkit widgets
CMAKE_ARGS=	-DWITH_KDE=off \
		-DUSE_QT5=on \
		-DWANT_CORE=off

OPTIONS_DEFINE=		NLS
OPTIONS_MULTI=		MODULE
MODULE_DESC=		Quassel components
OPTIONS_MULTI_MODULE=	CLIENT MONO
OPTIONS_DEFAULT=	CLIENT
OPTIONS_SUB=		yes

CLIENT_DESC=		Quassel client (for use with core)
CLIENT_CMAKE_ON=	-DWANT_QTCLIENT=on
CLIENT_CMAKE_OFF=	-DWANT_QTCLIENT=off

MONO_DESC=		Quassel standalone (monolithic binary: core+client combined)
MONO_CMAKE_ON=		-DWANT_MONO=on
MONO_CMAKE_OFF=		-DWANT_MONO=off

NLS_USE=		QT5=linguisttools_build

post-patch-NLS-off:
	${REINPLACE_CMD} -e '/add_subdirectory(po)/d' \
		${WRKSRC}/CMakeLists.txt

post-install-CLIENT-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/quasselclient
post-install-MONO-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/quassel

.endif

.include <bsd.port.mk>
