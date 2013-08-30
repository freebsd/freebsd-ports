# Created by: ijliao
# $FreeBSD$

PORTNAME=	mp3stat
PORTVERSION=	2.6.01
PORTREVISION=	11
CATEGORIES=	audio
MASTER_SITES=	https://signal-lost.homeip.net/files/ \
		http://www.sourcefiles.org/Multimedia/MP3/Tools/Processing/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Read information about mp3s and oggs bitstream

LICENSE=	GPLv2

OPTIONS_DEFINE=	VORBIS DOCS
OPTIONS_DEFAULT=	VORBIS

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		gmake
USE_GNOME=	gtk20

CXX+=		-I${LOCALBASE}/include -L${LOCALBASE}/lib \
		-Wl,--rpath,${LOCALBASE}/lib

PORTDOCS=	README
PLIST_FILES=	bin/mp3stat \
		lib/mp3stat/input_mp3.so \
		lib/mp3stat/ui_gtk2.so \
		lib/mp3stat/ui_console.so
PLIST_DIRS=	lib/mp3stat

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
PLIST_FILES+=	lib/mp3stat/input_vorb.so
.else
MAKE_ARGS+=	VORBIS=""
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|@$${CXX}|$${CXX}|g ; \
		 s|-ldl|-lz|g ; \
		 s|-lc||g ; \
		 s|-Wl,-soname,.*\.so\.1||g ; \
		 s|-fpic|-fPIC|g ; \
		 s|^CXX|#CXX|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3stat ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/mp3stat
	${INSTALL_DATA} ${WRKSRC}/ui/gtk/ui_gtk2.so ${PREFIX}/lib/mp3stat
	${INSTALL_DATA} ${WRKSRC}/ui/console/ui_console.so ${PREFIX}/lib/mp3stat
	${INSTALL_DATA} ${WRKSRC}/input/mp3/input_mp3.so ${PREFIX}/lib/mp3stat
.if ${PORT_OPTIONS:MVORBIS}
	${INSTALL_DATA} ${WRKSRC}/input/vorbis/input_vorb.so ${PREFIX}/lib/mp3stat
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
