# New ports collection makefile for:   avifile
# Date created: 	16 September 2000
# Whom: 		Holger Lamm
#
# $FreeBSD$
#

PORTNAME=	avifile
PORTVERSION=	0.49
CATEGORIES=	graphics
MASTER_SITES=	http://ernie.eit.uni-kl.de/avifile/ \
		http://divx.euro.ru/ \
		http://www.toon.eu.org/divx/
DISTFILES=	avifile-${PORTVERSION}.tar.gz \
		binaries-${CODEC_VERSION}.zip
EXTRACT_ONLY=	avifile-${PORTVERSION}.tar.gz

MAINTAINER=	holger@eit.uni-kl.de

LIB_DEPENDS=	SDL-1.1.2:${PORTSDIR}/devel/sdl-devel
BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

RESTRICTED=	Unsure of codec\'s license
RESTRICTED_FILES=	binaries-${CODEC_VERSION}.zip

ONLY_FOR_ARCHS= i386
USE_QT2=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		MOC="${MOC}"
CONFIGURE_ARGS+= --enable-mmx \
		--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib \
		--with-win32-path=${LOCALBASE}/lib/win32

CODEC_VERSION=	000918

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
MOC?=		${X11BASE}/bin/moc2

post-extract:
	@${LOCALBASE}/bin/unzip ${DISTDIR}/binaries-${CODEC_VERSION}.zip \
		-d ${WRKDIR}/codecs

#post-build:
#	(cd ${WRKSRC}/samples && ${SETENV} ${MAKE_ENV} ${GMAKE})

post-install:
	@${MKDIR} ${PREFIX}/lib/win32
	@${INSTALL_DATA} ${WRKDIR}/codecs/* ${PREFIX}/lib/win32
	@/usr/bin/fmt < ${PKGMESSAGE}

.include <bsd.port.mk>
