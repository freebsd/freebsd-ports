# New ports collection makefile for:	esound
# Version required:	0.2.7
# Date created:		19 July 1998
# Whom:			Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.6 1998/12/26 05:56:52 vanilla Exp $
#

DISTNAME=	esound-0.2.7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	esound
#MASTER_SITES=	ftp://ftp.enlightenment.org/pub/enlightenment/enlightenment/ \
#		ftp://www.rasterman.com/pub/enlightenment/enlightenment/ \
#		ftp://ftp.labs.redhat.com/pub/imlib/TAR/

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	audiofile.0:${PORTSDIR}/audio/libaudiofile

GNU_CONFIGURE=	yes

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
