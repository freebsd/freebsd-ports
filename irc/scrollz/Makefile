# New ports collection makefile for:	ScrollZ
# Date created:		10 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	scrollz
PORTVERSION=	1.8l
CATEGORIES=	irc ipv6
MASTER_SITES=	ftp://ftp.scrollz.com/pub/ScrollZ/source/ \
		ftp://ftp.stealth.net/pub/mirrors/ftp.scrollz.com/pub/ScrollZ/source
DISTNAME=	ScrollZ-${PORTVERSION}

MAINTAINER=	petef@databits.net

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-ipv6

MAKE_ENV+=	IRCLIB="${PREFIX}/share/scrollz"

PLIST_SUB+=	SCROLLZ_VER="${PORTVERSION}"

post-patch:
	@${PERL} -pi -e 's!^IRCLIB =!IRCLIB ?=!' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
