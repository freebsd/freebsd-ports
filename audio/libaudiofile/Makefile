# New ports collection makefile for:	libaudiofile
# Version required:			0.1.5
# Date created:				22 Dec 1998
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.1.1.1 1998/12/23 19:08:50 vanilla Exp $
#

DISTNAME=	libaudiofile-0.1.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	libaudiofile

MAINTAINER=	vanilla@FreeBSD.ORG

GNU_CONFIGURE=	yes

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
