# New ports collection makefile for:	libPropList
# Version required:			0.8.3
# Date Created:				6 December 1998
# Whom:					Glenn Johnson
#
# $Id: Makefile,v 1.2 1999/01/27 08:31:49 fenner Exp $
#

DISTNAME=	libPropList-0.8.3
PKGNAME=	libproplist-0.8.3
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	libPropList

MAINTAINER=    gljohns@bellsouth.net

GNU_CONFIGURE=	yes

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
