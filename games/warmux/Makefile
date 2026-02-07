PORTNAME=	warmux
DISTVERSION=	11.04.1
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	http://ftp.nluug.nl/ibiblio/distributions/slitaz/sources/packages-cooking/w/ \
		http://mirror.clarkson.edu/slitaz/sources/packages/w/ \
		http://ftp.ec-m.fr/pub/OpenBSD/distfiles/ \
		https://ftp.uni-erlangen.de/gentoo/distfiles/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Turn-based artillery game with free software mascots
WWW=		https://web.archive.org/web/20170513192248/http://gna.org/projects/warmux/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxml++-2.6.so:textproc/libxml++26 \
		libcurl.so:ftp/curl

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ENV=	cxx_present=yes
USES=		compiler dos2unix gmake pkgconfig sdl tar:bzip2
USE_SDL=	sdl image mixer ttf gfx net
DOS2UNIX_GLOB=	fixed_class.h

# build ignores CXXFLAGS
CFLAGS+=	${CFLAGS_${CHOSEN_COMPILER_TYPE}}
CFLAGS_clang=	-Wno-c++11-narrowing
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:R}

OPTIONS_DEFINE=	FRIBIDI SERVER NLS DEBUG
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ENABLE=	debug logging

FRIBIDI_DESC=		Enable bi-directional unicode support
FRIBIDI_LIB_DEPENDS=	libfribidi.so:converters/fribidi
FRIBIDI_CONFIGURE_ENABLE=	fribidi

NLS_USES=		gettext localbase:ldflags
NLS_CONFIGURE_ENABLE=	nls

SERVER_DESC=		Enable dedicated server
SERVER_CONFIGURE_ENABLE=	servers

post-patch:
	${REINPLACE_CMD} -e "s,-Werror,," ${WRKSRC}/Makefile.in \
	${WRKSRC}/src/Makefile.in ${WRKSRC}/configure
	${REINPLACE_CMD} -e "s,warmux_files.desktop,," ${WRKSRC}/data/Makefile.in
	${FIND} -d ${WRKSRC}/data/ -name "*.*~" -delete

.include <bsd.port.mk>
