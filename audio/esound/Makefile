# New ports collection makefile for:	esound
# Version required:	0.2.4
# Date created:		19 Jily 1998
# Whom:			Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $ID:$
#

DISTNAME=	esound-0.2.4
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.enlightenment.org/pub/enlightenment/enlightenment/ \
		ftp://www.rasterman.com/pub/enlightenment/enlightenment/ \
		ftp://ftp.labs.redhat.com/pub/imlib/TAR/

MAINTAINER=	vanilla@FreeBSD.ORG

USE_GMAKE=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/esound

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
