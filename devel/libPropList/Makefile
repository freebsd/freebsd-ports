# New ports collection makefile for:	libPropList
# Version required:			0.8.3
# Date Created:				6 December 1998
# Whom:					Glenn Johnson
#
# $Id: Makefile,v 1.3 1999/02/02 14:30:27 vanilla Exp $
#

DISTNAME=	libPropList-0.8.3
PKGNAME=	libproplist-0.8.3
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/libPropList

MAINTAINER=    gljohns@bellsouth.net

GNU_CONFIGURE=	yes

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
