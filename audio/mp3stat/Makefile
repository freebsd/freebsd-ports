# Created by: ijliao
# $FreeBSD$

PORTNAME=	mp3stat
PORTVERSION=	2.6.01
PORTREVISION=	12
CATEGORIES=	audio
MASTER_SITES=	https://signal-lost.homeip.net/files/ \
		http://www.sourcefiles.org/Multimedia/MP3/Tools/Processing/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Read information about mp3s and oggs bitstream

BROKEN=		unfetchable

LICENSE=	GPLv2

OPTIONS_DEFINE=	VORBIS DOCS
OPTIONS_DEFAULT=	VORBIS

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		dos2unix gmake pkgconfig
DOS2UNIX_FILES=	ui/console/cli.cpp
USE_GNOME=	gtk20

CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -Wl,--rpath,${LOCALBASE}/lib

PORTDOCS=	README
PLIST_FILES=	bin/mp3stat \
		lib/mp3stat/input_mp3.so \
		lib/mp3stat/ui_gtk2.so \
		lib/mp3stat/ui_console.so

VORBIS_LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis
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
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} mp3stat ${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/mp3stat
	(cd ${WRKSRC}/ui/gtk && ${INSTALL_LIB} ui_gtk2.so \
		${STAGEDIR}${PREFIX}/lib/mp3stat)
	(cd ${WRKSRC}/ui/console && ${INSTALL_LIB} ui_console.so \
		${STAGEDIR}${PREFIX}/lib/mp3stat)
	(cd ${WRKSRC}/input/mp3 && ${INSTALL_LIB} input_mp3.so \
		${STAGEDIR}${PREFIX}/lib/mp3stat)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README ${STAGEDIR}${DOCSDIR})
do-install-VORBIS-on:
	(cd ${WRKSRC}/input/vorbis && ${INSTALL_LIB} input_vorb.so \
		${STAGEDIR}${PREFIX}/lib/mp3stat)

.include <bsd.port.mk>
