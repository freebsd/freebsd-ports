# New ports collection makefile for:   glib
# Version required:		1.1.0
# Date Created:			28 July 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id:$
#

DISTNAME=	glib-1.1.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gimp.org/pub/gtk/v1.1/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.1/ \
		http://www.ameth.org/gimp/pub/gtk/v1.1/

MAINTAINER=	vanilla@FreeBSD.ORG

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV=	INSTALL='$${INSTALL} -c'

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
