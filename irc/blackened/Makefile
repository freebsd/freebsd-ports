# New ports collection makefile for:	Blackened IRC client
# Date created:		11 Jun 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	blackened
PORTVERSION=	1.8.0
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.blackened.com/pub/irc/blackened/

MAINTAINER=	toast@blackened.com

GNU_CONFIGURE=	yes
PLIST_SUB=	VERSION=${PORTVERSION}
CONFIGURE_ARGS=	--prefix=${PREFIX}
INSTALL_TARGET=	installeverything

pre-configure:
	${PERL} -pi -e "s@long_to_time@ch_to_time@g" ${WRKSRC}/source/toast.c

.include <bsd.port.mk>
