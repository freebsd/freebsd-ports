# Created by: Shen Chuan-Hsing
# $FreeBSD$

PORTNAME=	qterm
PORTVERSION=	0.5.12
PORTREVISION=	2
CATEGORIES=	chinese
MASTER_SITES=	SF/qterm/qterm/${PORTVERSION}

MAINTAINER=	kaiwang27@gmail.com
COMMENT=	BBS client for BSD/Linux

USES=		tar:bzip2 cmake perl5
USE_PERL5=	build
USE_QT4=	codecs-cn_run codecs-tw_run gui help-tools_build \
		linguist_build moc_build network qt3support_build \
		qmake_build rcc_build uic_build xml
USE_XORG=	x11 ice
INSTALLS_ICONS=	yes

CONFLICTS_INSTALL=	torque-[0-9]*

OPTIONS_DEFINE=	DBUS OPENSSL PHONON QTSCRIPT KDE
OPTIONS_DEFAULT=	DBUS OPENSSL PHONON QTSCRIPT

PHONON_DESC=	Multimedia support via Phonon
QTSCRIPT_DESC=	Scripting support via QtScript Bindings
KDE_DESC=	Password management via KWallet

OPENSSL_USE=	OPENSSL=yes
OPENSSL_CMAKE_ON=	-DQTERM_ENABLE_SSH:BOOL=TRUE
OPENSSL_CMAKE_OFF=	-DQTERM_ENABLE_SSH:BOOL=FALSE

DBUS_USE=	QT4=dbus
DBUS_CMAKE_ON=	-DQTERM_ENABLE_DBUS:BOOL=TRUE
DBUS_CMAKE_OFF=	-DQTERM_ENABLE_DBUS:BOOL=FALSE

PHONON_USE=	QT4=phonon
PHONON_CMAKE_ON=	-DQTERM_ENABLE_PHONON:BOOL=TRUE
PHONON_CMAKE_OFF=	-DQTERM_ENABLE_PHONON:BOOL=FALSE

QTSCRIPT_USE=	QT4=script
QTSCRIPT_RUN_DEPENDS=	${QT_PLUGINDIR}/script/libqtscript_core.so:devel/qtscriptgenerator
QTSCRIPT_CMAKE_ON=	-DQTERM_ENABLE_SCRIPT:BOOL=TRUE
QTSCRIPT_CMAKE_OFF=	-DQTERM_ENABLE_SCRIPT:BOOL=FALSE

KDE_USE=	KDE4=kdelibs,automoc4

post-patch-KDE-off:
	${REINPLACE_CMD} -e "/^find_package(KDE4)/d" ${WRKSRC}/CMakeLists.txt
post-patch:
	${REINPLACE_CMD} -e "/^set(QT_MIN_VERSION/d" ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
