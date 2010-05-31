# New ports collection makefile for:	lush
# Date created:				20 May 2003
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$

PORTNAME=	lush
PORTVERSION=	1.2.1
PORTREVISION=	8
CATEGORIES=	lang
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A high level object-oriented programming language

USE_GETTEXT=	yes
USE_XORG=	xt xft
USE_GL=		yes
USE_SDL=	sdl image
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/lush

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LIBS="${LIBS} ${PTHREAD_LIBS} -lintl -L${LOCALBASE}/lib"

CONFIGURE_ARGS=	--without-bfd

MAN1=		lush.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not build on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -E -e \
		's|opt=.+$$||; \
		s|-O3||; \
		s|-Wall||; \
		s|-pthread|${PTHREAD_LIBS}|' \
		${WRKSRC}/configure

pre-install:
	@${FIND} ${WRKSRC}/ -name "*.bak" -delete

.include <bsd.port.post.mk>
