# New ports collection makefile for:	dnstop
# Date created:		31 October 2002
# Whom:			fenner
#
# $FreeBSD$

PORTNAME=	dnstop
PORTVERSION=	20021125
CATEGORIES=	net
MASTER_SITES=	http://dnstop.measurement-factory.com/src/

MAINTAINER=	fenner@FreeBSD.Org

NO_WRKSUBDIR=	true

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnstop ${PREFIX}/bin

.include <bsd.port.mk>
