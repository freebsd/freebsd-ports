# New ports collection makefile for:	guile
# Version required:	1.3.4
# Date created:		2 November 1997
# Whom:			jseger@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=	guile-1.3.4
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.guile.org/pub/
MASTER_SITE_SUBDIR=	guile

MAINTAINER=	jseger@FreeBSD.org

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-threads

USE_LIBTOOL=	yes
LIBTOOLFILES=	configure guile-readline/configure

PLIST_SUB=	GUILE_VER=1.3.4

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
