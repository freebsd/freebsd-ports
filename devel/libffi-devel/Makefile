# New ports collection makefile for:	libffi
# Date created:			14, June, 1998
# Whom:				Horance Chou <horance@freedom.ie.cycu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	libffi
PORTVERSION=	1.20
CATEGORIES=	devel
MASTER_SITES=	ftp://sourceware.cygnus.com/pub/libffi/

MAINTAINER=	horance@freedom.ie.cycu.edu.tw

USE_LIBTOOL=	yes
CONFIGURE_TARGET=	# empty

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
