# New ports collection makefile for:	moftpd
# Date created:				Mar 19, 2004
# Whom:					Clement Laforet <clement@FreeBSD>org>
#
# $FreeBSD$
#

PORTNAME=	moftpd
PORTVERSION=	1.2
CATEGORIES=	ftp ipv6
MASTER_SITES=	ftp://ftp.morth.org/moftpd/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	clement

MAINTAINER=	clement@FreeBSD.org
COMMENT=	A powerful FTP server supporting IPv6, TLS, and much more

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
CONFIGURE_ENV+=	LIBS=-lcrypt
MAN8=		moftpd.8 moftpadmin.8

.include <bsd.port.mk>
