# New ports collection makefile for:  mad
# Date created:        18 November 2000
# Whom:                Jason R. Mastaler <jason-freebsd@mastaler.com> et al.
#
# $FreeBSD$
#

PORTNAME=	mad
PORTVERSION=	0.12.1b
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.mars.org/pub/mpeg/
MASTER_SITE_SUBDIR=	mad

MAINTAINER=	jason-freebsd@mastaler.com

GNU_CONFIGURE=	yes
# This port is not CFLAGS SAFE, something like CFLAGS="-O -Os"
# breaks configure and configure likes to use -O2 instead of
# trusting the system. We'll have it use -O instead of -O*
# since this configure requires a standard and this has
# been the system standard
CONFIGURE_ENV=	CFLAGS="-O -pipe"
USE_GMAKE=	yes
USE_LIBTOOL=	yes

MAN1=			abxtest.1 madplay.1

.include <bsd.port.mk>
