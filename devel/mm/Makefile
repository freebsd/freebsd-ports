# New ports collection makefile for:   mm
# Version required:		1.0.0
# Date Created:			14 March 1999
# Whom:				Ralf S. Engelschall
#
# $Id: Makefile,v 1.1.1.1 1999/03/24 14:14:13 rse Exp $
#

DISTNAME=	mm-1.0.0
CATEGORIES=	devel
MASTER_SITES=	http://www.engelschall.com/sw/mm/

MAINTAINER=	rse@engelschall.com

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

MAN1=		mm-config.1
MAN3=		mm.3

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

test:
	@cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
