# New ports collection makefile for: gdbm
# Date created:		8 Apr 1996
# Whom:			Brent J. Nordquist <bjn@visi.com>
#
# $FreeBSD$
#

PORTNAME=	gdbm
PORTVERSION=	1.8.0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gdbm

MAINTAINER=	cyrille.lefevre@laposte.net

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
# PREFIX isn't honored. force it w/ prefix.
MAKE_ARGS=	prefix=${PREFIX}

MAN3=		gdbm.3

INSTALL_INFO?=	install-info

post-install:
	@${INSTALL_INFO} ${PREFIX}/info/${PORTNAME}.info ${PREFIX}/info/dir

.include <bsd.port.mk>
