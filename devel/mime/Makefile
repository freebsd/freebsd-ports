# New ports collection makefile for:	mime
# Date created:				3 June 2000
# Whom:					jmg
#
# $FreeBSD$
#

PORTNAME=	mime
PORTVERSION=	1.0
CATEGORIES=	devel
MASTER_SITES=	http://resnet.uoregon.edu/~gurney_j/jmpc/dist/

MAINTAINER=	jmg@FreeBSD.org

GNU_CONFIGURE=	yes

post-install:
	@${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
