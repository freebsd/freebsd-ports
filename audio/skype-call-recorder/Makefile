# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	skype-call-recorder
PORTVERSION=	0.11
CATEGORIES=	audio
MASTER_SITES=	http://atdot.ch/scr/files/${PORTVERSION}/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Skype call recorder

LICENSE=	GPLv2

LIB_DEPENDS=	libmp3lame.so:audio/lame \
		libid3.so:audio/id3lib \
		libvorbisenc.so:audio/libvorbis

USES=		cmake
USE_QT4=	corelib dbus gui network \
		qmake_build moc_build rcc_build uic_build

PLIST_FILES=	bin/skype-call-recorder \
		share/applications/skype-call-recorder.desktop \
		share/icons/hicolor/128x128/apps/skype-call-recorder.png

post-patch:
	@${REINPLACE_CMD} -e '/CMAKE_CXX_FLAGS_RELEASE/d' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's,date --utc,TZ=UTC date,' \
		${WRKSRC}/makeversion

.include <bsd.port.mk>
