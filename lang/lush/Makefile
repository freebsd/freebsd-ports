# New ports collection makefile for:	lush
# Date created:				20 May 2003
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$

PORTNAME=	lush
PORTVERSION=	0.99
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lush

MAINTAINER=	dyeske@yahoo.com
COMMENT=	A high level object-oriented programming language

USE_GETTEXT=	yes
USE_X_PREFIX=	yes
USE_GL=		yes
USE_SDL=	sdl image
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LIBS="${LIBS} ${PTHREAD_LIBS} -lintl -L${LOCALBASE}/lib"

CONFIGURE_ARGS=	--without-bfd

MAN1=		lush.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Does not build on sparc64"
.endif

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

.include <bsd.port.post.mk>
