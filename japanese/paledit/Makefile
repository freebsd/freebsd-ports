# New ports collection makefile for:	paledit
# Date created:		14 Jan 1999
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	paledit
PORTVERSION=	0.91
CATEGORIES=	japanese sysutils
MASTER_SITES=	http://www.swlab.csce.kyushu-u.ac.jp/~nom/prj/paledit/

MAINTAINER=	shige@FreeBSD.org

USE_PERL5=	yes
GNU_CONFIGURE=	yes

post-install:
	@${CHMOD} 2754 ${PREFIX}/sbin/paledit
	@${CHOWN} root:dialer ${PREFIX}/sbin/paledit

.include <bsd.port.mk>
