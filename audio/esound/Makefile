# New ports collection makefile for:	esound
# Version required:	0.2.8
# Date created:		19 July 1998
# Whom:			Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.7 1999/01/27 08:31:46 fenner Exp $
#

DISTNAME=	esound-0.2.8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	gnome-1.0/sources
#MASTER_SITES=	ftp://ftp.enlightenment.org/pub/enlightenment/enlightenment/ \
#		ftp://www.rasterman.com/pub/enlightenment/enlightenment/ \
#		ftp://ftp.labs.redhat.com/pub/imlib/TAR/

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	audiofile.0:${PORTSDIR}/audio/libaudiofile

GNU_CONFIGURE=	yes

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
