# New ports collection makefile for:	libtool
# Date created:		6 May 1998
# Whom:			Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $FreeBSD$
#

PORTNAME=	libtool
PORTVERSION=	1.3.4
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	libtool

MAINTAINER=	ports@FreeBSD.org

# This port has not been upgraded to 1.4 because it is used by about 30% of
# the ports collection, and more testing is needed.  If someone can supply a
# working patch then it will be upgraded.

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PREFIX=${PREFIX}

.ifdef USE_LIBTOOL
.error You have `USE_LIBTOOL' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

.include <bsd.port.mk>
