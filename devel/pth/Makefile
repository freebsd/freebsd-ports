# New ports collection makefile for:   nps
# Version required:		0.9.11
# Date Created:			23 May 1999
# Whom:				Ralf S. Engelschall
#
# $Id: Makefile,v 1.4 1999/05/28 10:38:27 rse Exp $
#

DISTNAME=	nps-0.9.11
CATEGORIES=	devel
MASTER_SITES=	http://www.engelschall.com/sw/nps/ \
		ftp://ftp.engelschall.com/sw/nps/

MAINTAINER=	rse@engelschall.com

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

MAN1=		nps-config.1
MAN3=		nps.3

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
