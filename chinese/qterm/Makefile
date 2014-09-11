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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
CMAKE_ARGS+=	-DQTERM_ENABLE_SSH:BOOL=TRUE
.else
CMAKE_ARGS+=	-DQTERM_ENABLE_SSH:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MDBUS}
USE_QT4+=	dbus
CMAKE_ARGS+=	-DQTERM_ENABLE_DBUS:BOOL=TRUE
.else
CMAKE_ARGS+=	-DQTERM_ENABLE_DBUS:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MPHONON}
USE_QT4+=	phonon
CMAKE_ARGS+=	-DQTERM_ENABLE_PHONON:BOOL=TRUE
.else
CMAKE_ARGS+=	-DQTERM_ENABLE_PHONON:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MQTSCRIPT}
USE_QT4+=	script
RUN_DEPENDS+=	${QT_PLUGINDIR}/script/libqtscript_core.so:${PORTSDIR}/devel/qtscriptgenerator
CMAKE_ARGS+=	-DQTERM_ENABLE_SCRIPT:BOOL=TRUE
.else
CMAKE_ARGS+=	-DQTERM_ENABLE_SCRIPT:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MKDE}
USE_KDE4=	kdelibs automoc4
.endif

post-patch:
.if !${PORT_OPTIONS:MKDE}
	${REINPLACE_CMD} -e "/^find_package(KDE4)/d" ${WRKSRC}/CMakeLists.txt
.endif
	${REINPLACE_CMD} -e "/^set(QT_MIN_VERSION/d" ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
