# New ports collection makefile for:	libffi
# Version required:		1.20
# Date created:			14, June, 1998
# Whom:				Horance Chou <horance@freedom.ie.cycu.edu.tw>
#
# $Id: Makefile,v 1.8 1999/03/08 07:28:22 asami Exp $
#

DISTNAME=       libffi-1.20
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.cygnus.com/pub/green/

MAINTAINER=     horance@freedom.ie.cycu.edu.tw

USE_LIBTOOL=  yes
CONFIGURE_TARGET=	# empty

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
