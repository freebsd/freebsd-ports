# New ports collection makefile for:	esound
# Version required:	0.2.4
# Date created:		19 July 1998
# Whom:			Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.2 1998/07/20 10:01:55 asami Exp $
#

DISTNAME=	esound-0.2.4
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.enlightenment.org/pub/enlightenment/enlightenment/ \
		ftp://www.rasterman.com/pub/enlightenment/enlightenment/ \
		ftp://ftp.labs.redhat.com/pub/imlib/TAR/

MAINTAINER=	vanilla@FreeBSD.ORG

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/esound

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
