# New ports collection makefile for:	mime
# Date created:				3 June 2000
# Whom:					jmg
#
# $FreeBSD$
#

PORTNAME=	mime
PORTVERSION=	1.1
CATEGORIES=	devel
MASTER_SITES=	http://resnet.uoregon.edu/~gurney_j/jmpc/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library to parse mime data

GNU_CONFIGURE=	yes
CFLAGS+="-fPIC"

post-install:
	@${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
