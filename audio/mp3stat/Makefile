# Created by: ijliao
# $FreeBSD$

PORTNAME=	mp3stat
PORTVERSION=	2.6.01
PORTREVISION=	12
CATEGORIES=	audio
MASTER_SITES=	http://BSDforge.com/projects/source/audio/mp3stat/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Read information about an MP3's, or OGG's bitstream

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		dos2unix gmake localbase pkgconfig
DOS2UNIX_FILES=	ui/console/cli.cpp
USE_GNOME=	gtk20

LDFLAGS+=	-Wl,--rpath,${LOCALBASE}/lib

PORTDOCS=	README
PLIST_FILES=	bin/mp3stat \
		lib/mp3stat/input_mp3.so \
		lib/mp3stat/ui_gtk2.so \
		lib/mp3stat/ui_console.so

OPTIONS_DEFINE=		VORBIS DOCS
OPTIONS_DEFAULT=	VORBIS

VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
VORBIS_PLIST_FILES=	lib/mp3stat/input_vorb.so
VORBIS_MAKE_ARGS_OFF=	VORBIS=""

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|@$${CXX}|$${CXX}|g ; \
		 s|-ldl|-lz|g ; \
		 s|-lc|$${LDFLAGS}|g ; \
		 s|-Wl,-soname,.*\.so\.1||g ; \
		 s|-fpic|-fPIC|g ; \
		 s|^CXX|#CXX|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3stat ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/mp3stat
	${INSTALL_LIB} ${WRKSRC}/ui/gtk/ui_gtk2.so ${STAGEDIR}${PREFIX}/lib/mp3stat
	${INSTALL_LIB} ${WRKSRC}/ui/console/ui_console.so ${STAGEDIR}${PREFIX}/lib/mp3stat
	${INSTALL_LIB} ${WRKSRC}/input/mp3/input_mp3.so ${STAGEDIR}${PREFIX}/lib/mp3stat

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

do-install-VORBIS-on:
	${INSTALL_LIB} ${WRKSRC}/input/vorbis/input_vorb.so \
		${STAGEDIR}${PREFIX}/lib/mp3stat

.include <bsd.port.mk>
