# ex:ts=8
# ports collection makefile for:	cscope
# Date created:		1998-11-21
# Whom:			Castor Fu
#
# $FreeBSD$
#

PORTNAME=	cscope
PORTVERSION=	15.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	conrads@cox.net
COMMENT=	An interactive C program browser

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-yacc

PLIST_FILES=	bin/cscope \
		bin/ocs
MAN1=		cscope.1

.include <bsd.port.mk>
