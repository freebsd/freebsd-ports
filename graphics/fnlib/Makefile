# New ports collection makefile for:	fnlib
# Version required:	0.4
# Date created:		23 June 1997
# Whom:			brett@peloton.physics.montana.edu
#
# $Id: Makefile,v 1.5 1998/09/23 17:16:35 vanilla Exp $
#

DISTNAME=	fnlib-0.4
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/ \
		ftp://ftp.gnome.org/pub/GNOME/sources/
#MASTER_SITES=	ftp://www.rasterman.com/pub/enlightenment/enlightenment/ \
#		ftp://ftp.enlightenment.org/pub/enlightenment/enlightenment/ \
#		ftp://ftp.labs.redhat.com/pub/imlib/TAR/

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	Imlib.1:${PORTSDIR}/graphics/imlib

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
