# New ports collection makefile for:   mumble
# Date created:        1 February 2009
# Whom:                marius nuennerich
#
# $FreeBSD$
#

PORTNAME=	mumble
PORTVERSION=	1.1.7
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/Mumble/${PORTVERSION}

MAINTAINER=	marius@nuenneri.ch
COMMENT=	A voice chat software primarily intended for use while gaming

LIB_DEPENDS+=	speex.1:${PORTSDIR}/audio/speex \
		boost_iostreams:${PORTSDIR}/devel/boost-libs

USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui opengl dbus xml sql network linguist_build l10n \
		moc_build qmake_build rcc_build uic_build

USE_XORG=	ice
HAS_CONFIGURE=	yes
INSTALLS_ICONS=	yes

CONFIG=		no-server no-alsa no-speechd no-bundled-speex no-update no-g15 \
		no-portaudio no-pulseaudio no-xevie

MAN1=		mumble.1 mumble-overlay.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		Does not compile on FreeBSD < 7.0
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||' ${WRKSRC}/overlay_gl/overlay_gl.pro
	@${REINPLACE_CMD} -e 's|qt_ja_jp|qt_ja_JP|' \
	${WRKSRC}/src/mumble/mumble_qt.qrc ${WRKSRC}/src/mumble/mumble.pro

do-configure:
	cd ${WRKSRC} && ${SETENV} QMAKESPEC=${QMAKESPEC} ${QMAKE} PREFIX=${PREFIX} main.pro "CONFIG+=${CONFIG}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/release/mumble ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mumble-overlay ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/services
	${INSTALL_DATA} ${WRKSRC}/scripts/mumble.protocol ${PREFIX}/share/services
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/scripts/mumble.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/icons/mumble.xpm ${PREFIX}/share/pixmaps
	for f in 16 32 48 64; do \
		${MKDIR} ${PREFIX}/share/icons/hicolor/$${f}x$${f}/apps; \
		${INSTALL_DATA} ${WRKSRC}/icons/mumble.$${f}x$${f}.png ${PREFIX}/share/icons/hicolor/$${f}x$${f}/apps; \
	done
	${INSTALL_MAN} ${WRKSRC}/man/mumble.1 ${MANPREFIX}/man/man1/mumble.1
	${INSTALL_MAN} ${WRKSRC}/man/mumble-overlay.1 ${MANPREFIX}/man/man1/mumble-overlay.1

.include <bsd.port.post.mk>
