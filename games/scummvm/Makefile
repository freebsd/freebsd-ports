# New ports collection makefile for:	scummvm
# Date created:				Tue Sep  2 23:34:32 BST 2003
# Whom:				Alex Trull <alexander@trull.com>
#
# $FreeBSD$
#

PORTNAME=	scummvm
PORTVERSION=	0.6.0
CATEGORIES=	games emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	alexander@trull.com
COMMENT=	Graphical Adventure Game Virtual Machine

USE_BZIP2=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_SDL=	sdl

CONFIGURE_ARGS=--with-sdl-prefix=${LOCALBASE} \
		--disable-alsa \
		--with-zlib-prefix=/usr \
		--disable-debug

OPTIONS=	VORBIS "Enable Ogg Vorbis support" off \
		MAD "Enable mad (MP3) support" on \
		MPEG2 "Enable MPEG2 support" off

MAN6=		scummvm.6

DOCS=		NEWS README TODO

.include <bsd.port.pre.mk>

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	ogg.5:${PORTSDIR}/audio/libogg \
		vorbis.3:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--with-ogg-prefix=${LOCALBASE} \
		--with-vorbis-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-vorbis
.endif

.if !defined(WITHOUT_MAD)
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad
CONFIGURE_ARGS+=--with-mad-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-mad
.endif

.if defined(WITH_MPEG2)
LIB_DEPENDS+=	mpeg2.0:${PORTSDIR}/multimedia/libmpeg2
CONFIGURE_ARGS+=--with-mpeg2-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-mpeg2
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/-O//' ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/scummvm ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/scummvm.6 ${PREFIX}/man/man6

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
