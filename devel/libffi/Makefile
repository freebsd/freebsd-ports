# New ports collection makefile for:	libffi
# Version required:		1.20
# Date created:			14, June, 1998
# Whom:				Horance Chou <horance@freedom.ie.cycu.edu.tw>
#
# $Id: Makefile,v 1.6 1998/11/16 15:55:46 vanilla Exp $
#

DISTNAME=       libffi-1.20
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.cygnus.com/pub/green/

MAINTAINER=     horance@freedom.ie.cycu.edu.tw

GNU_CONFIGURE=  yes

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
