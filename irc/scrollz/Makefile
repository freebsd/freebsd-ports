# New ports collection makefile for:	ScrollZ
# Date created:		10 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	scrollz
PORTVERSION=	1.9
PORTREVISION=	2
CATEGORIES=	irc ipv6
MASTER_SITES=	http://scrollz.broken.com/source/ \
		ftp://ftp.du.se/pub/mirrors/ScrollZ/source/
DISTNAME=	ScrollZ-${PORTVERSION}

MAINTAINER=	damm@yazzy.org
COMMENT=	Enhanced ircII client that supports scripts, colors, and more

USE_GMAKE= yes
USE_PERL5_BUILD=yes
IS_INTERACTIVE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-ipv6 --with-ssl

MAKE_ENV+=	IRCLIB="${PREFIX}/share/scrollz"

PLIST_SUB+=	SCROLLZ_VER="${PORTVERSION}"

post-patch:
	@${PERL} -pi -e 's!^IRCLIB =!IRCLIB ?=!' ${WRKSRC}/Makefile.in

pre-build:
.if !defined(BATCH)
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} -o SZdist \
		SZdist.c)
	@(cd $(WRKSRC); ./SZdist)
.endif

.include <bsd.port.mk>
