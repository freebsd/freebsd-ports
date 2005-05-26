# ex:ts=8
# Ports collection makefile for:	mp3stat
# Date created:			Mar 20, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mp3stat
PORTVERSION=	2.6.01
CATEGORIES=	audio
MASTER_SITES=	https://signal-lost.homeip.net/files/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Read information about mp3s and oggs bitstream

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GNOME=	gtk20
USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"

PLIST_FILES=	bin/mp3stat \
		lib/mp3stat/input_mp3.so \
		lib/mp3stat/ui_gtk2.so \
		lib/mp3stat/ui_console.so
PLIST_DIRS=	lib/mp3stat

CXX+=		-I${LOCALBASE}/include -L${LOCALBASE}/lib \
		-Wl,--rpath,${LOCALBASE}/lib

OPTIONS=	VORBIS "Ogg/Vorbis support" on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
LIB_DEPENDS+=	magic.1:${PORTSDIR}/sysutils/file
.endif

.if ${OSVERSION} < 504000
BUILD_DEPENDS+=	${LOCALBASE}/include/magic.h:${PORTSDIR}/sysutils/file
.endif

.if defined(WITHOUT_VORBIS)
MAKE_ARGS+=	VORBIS=""
.else
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
PLIST_FILES+=	lib/mp3stat/input_vorb.so
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	README
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|@$${CXX}|$${CXX}|g ; \
		 s|-ldl|-lz|g ; \
		 s|-lc||g ; \
		 s|-Wl,-soname,.*\.so\.1||g ; \
		 s|-fpic|-fPIC|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3stat ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/mp3stat
	${INSTALL_DATA} ${WRKSRC}/ui/gtk/ui_gtk2.so ${PREFIX}/lib/mp3stat
	${INSTALL_DATA} ${WRKSRC}/ui/console/ui_console.so ${PREFIX}/lib/mp3stat
	${INSTALL_DATA} ${WRKSRC}/input/mp3/input_mp3.so ${PREFIX}/lib/mp3stat
.if !defined(WITHOUT_VORBIS)
	${INSTALL_DATA} ${WRKSRC}/input/vorbis/input_vorb.so ${PREFIX}/lib/mp3stat
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
