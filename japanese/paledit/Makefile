# New ports collection makefile for:	paledit
# Version required:	1.0
# Date created:		14 Jan 1999
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1999/01/26 03:34:36 steve Exp $
#

DISTNAME=	paledit-0.91
PKGNAME=	ja-${DISTNAME}
CATEGORIES=	japanese sysutils
MASTER_SITES=	http://www.swlab.csce.kyushu-u.ac.jp/~nom/prj/paledit/

MAINTAINER=	shige@FreeBSD.ORG

USE_PERL5=	yes
GNU_CONFIGURE=	yes

post-install:
	@chmod 2754 ${PREFIX}/sbin/paledit
	@chown root:dialer ${PREFIX}/sbin/paledit

.include <bsd.port.mk>
