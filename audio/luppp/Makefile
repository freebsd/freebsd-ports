# $FreeBSD$

PORTNAME=	luppp
DISTVERSIONPREFIX=	release-
DISTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Live looping music creation tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjack.so:audio/jack \
		liblo.so:audio/liblo \
		libntk.so:x11-toolkits/ntk \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile

USES=		cmake compiler:c++11-lang gnome pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	openAVproductions
GH_PROJECT=	openAV-Luppp
USE_GNOME=	cairo
USE_XORG=	x11

PLIST_FILES=	bin/luppp

post-patch:
	@${REINPLACE_CMD} -e ' \
		s|execute_process(COMMAND git log --oneline -n1|execute_process(COMMAND echo "n/a"|' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e ' \
		s| -O3||; \
		s| -g||; \
		s|"x86_64"|"amd64"|' \
		${WRKSRC}/src/CMakeLists.txt

.include <bsd.port.mk>
