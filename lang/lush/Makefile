# New ports collection makefile for:	lush
# Date created:				20 May 2003
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$

PORTNAME=	lush
PORTVERSION=	0.99
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lush

MAINTAINER=	dyeske@yahoo.com
COMMENT=	A high level object-oriented programming language

LIB_DEPENDS=	SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		intl.5:${PORTSDIR}/devel/gettext-old

USE_X_PREFIX=	yes
USE_GL=		yes
USE_SDL=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LIBS="${LIBS} ${PTHREAD_LIBS} -lintl -L${LOCALBASE}/lib"

CONFIGURE_ARGS=	--without-bfd

MAN1=		lush.1

post-patch:
	@${REINPLACE_CMD} -E -e \
		's|opt=.+$$||; \
		s|-O3||; \
		s|-Wall||; \
		s|-pthread|${PTHREAD_LIBS}|' \
		${WRKSRC}/configure

	@${FIND} ${WRKSRC} | \
		${XARGS} ${EGREP} -l '(SDL/SDL)' | \
		${XARGS} ${REINPLACE_CMD} -e \
		's|SDL/SDL|SDL11/SDL|; \
		s|"libSDL"|\"libSDL-1.1.so.5\"|'

.include <bsd.port.mk>
