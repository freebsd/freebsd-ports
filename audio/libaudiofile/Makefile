# New ports collection makefile for:	libaudiofile
# Version required:			0.1.5
# Date created:				22 Dec 1998
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id$
#

DISTNAME=	libaudiofile-0.1.5
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/ \
		ftp://ftp.gnome.org/pub/GNOME/sources/ \
		ftp://ftp.68k.org/pub/michael/

MAINTAINER=	vanilla@FreeBSD.ORG

GNU_CONFIGURE=	yes

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
