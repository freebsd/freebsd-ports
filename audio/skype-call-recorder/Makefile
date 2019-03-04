# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	skype-call-recorder
PORTVERSION=	0.11
CATEGORIES=	audio
MASTER_SITES=	http://atdot.ch/scr/files/${PORTVERSION}/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Skype call recorder

LICENSE=	GPLv2

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

LIB_DEPENDS=	libmp3lame.so:audio/lame \
		libid3.so:audio/id3lib \
		libvorbisenc.so:audio/libvorbis

USES=		cmake qt:4
USE_QT=		corelib dbus gui network \
		qmake_build moc_build rcc_build uic_build

PLIST_FILES=	bin/skype-call-recorder \
		share/applications/skype-call-recorder.desktop \
		share/icons/hicolor/128x128/apps/skype-call-recorder.png

post-patch:
	@${REINPLACE_CMD} -e '/CMAKE_CXX_FLAGS_RELEASE/d' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's,date --utc,TZ=UTC date,' \
		${WRKSRC}/makeversion
# Avoid conflict with C++20 <version> by adding .txt suffix
	@${MV} ${WRKSRC}/version ${WRKSRC}/version.txt
	@${REINPLACE_CMD} -i .c++20 's,src/version,&.txt,' \
		${WRKSRC}/makeversion

.include <bsd.port.mk>
