# New ports collection makefile for:	fnlib
# Version required:	0.4
# Date created:		23 June 1997
# Whom:			brett@peloton.physics.montana.edu
#
# $Id: Makefile,v 1.8 1999/01/27 08:31:50 fenner Exp $
#

DISTNAME=	fnlib-0.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	enlightenment
#MASTER_SITES=	ftp://www.rasterman.com/pub/enlightenment/enlightenment/ \
#		ftp://ftp.enlightenment.org/pub/enlightenment/enlightenment/ \
#		ftp://ftp.labs.redhat.com/pub/imlib/TAR/

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	Imlib.3:${PORTSDIR}/graphics/imlib

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
