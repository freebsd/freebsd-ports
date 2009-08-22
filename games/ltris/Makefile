# New ports collection makefile for:	ltris
# Date created:				19 October 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ltris
PORTVERSION=	1.0.12
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SF/lgames/${PORTNAME}/1.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An another tetris clone but a good one with bunch of cool features

USE_SDL=	mixer sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|= @mixer_flag@|= @INTLLIBS@ @mixer_flag@|g ; \
		 s|--mode=666||g' ${WRKSRC}/src/Makefile.in

post-install:
	${CHOWN} root:games ${PREFIX}/bin/${PORTNAME}
	${CHMOD} 2755 ${PREFIX}/bin/${PORTNAME}
	${CHMOD} 664 ${PREFIX}/var/ltris.hscr
	${CHOWN} root:games ${PREFIX}/var/ltris.hscr

.include <bsd.port.post.mk>
