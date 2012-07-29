# New ports collection makefile for:	ltris
# Date created:				19 October 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ltris
PORTVERSION=	1.0.15
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SF/lgames/${PORTNAME}

MAINTAINER=	davide.italiano@gmail.com
COMMENT=	Another Tetris clone but a good one with bunch of cool features

USE_SDL=	mixer sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--localstatedir=${DATADIR}

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/icons|/pixmaps|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|= @mixer_flag@|= @INTLLIBS@ @mixer_flag@|g ; \
		 s|--mode=666||g' ${WRKSRC}/src/Makefile.in

post-install:
	@${CHMOD} 2755 ${PREFIX}/bin/${PORTNAME}
	@${CHOWN} root:games ${PREFIX}/bin/${PORTNAME}
	@${CHMOD} 0664 ${DATADIR}/${PORTNAME}.hscr
	@${CHOWN} root:games ${DATADIR}/${PORTNAME}.hscr

.include <bsd.port.post.mk>
