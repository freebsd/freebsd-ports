# New ports collection makefile for:   glib
# Version required:		1.1.2
# Date Created:			28 July 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.1.1.1 1998/07/28 15:22:15 vanilla Exp $
#

DISTNAME=	glib-1.1.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gimp.org/pub/gtk/v1.1/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.1/ \
		http://www.ameth.org/gimp/pub/gtk/v1.1/

MAINTAINER=	vanilla@FreeBSD.ORG

GNU_CONFIGURE=	yes
#USE_GMAKE=	yes

CONFIGURE_ENV=	INSTALL='$${INSTALL} -c'
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/glib

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
