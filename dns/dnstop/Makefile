# New ports collection makefile for:	dnstop
# Date created:		31 October 2002
# Whom:			fenner
#
# $FreeBSD$

PORTNAME=	dnstop
PORTVERSION=	20021030
CATEGORIES=	net
MASTER_SITES=	http://dnstop.measurement-factory.com/src/
DISTFILES=	dnstop.c Makefile
DIST_SUBDIR=	dnstop

MAINTAINER=	fenner@FreeBSD.Org

EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	.
NO_WRKSUBDIR=	true

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnstop ${PREFIX}/bin

.include <bsd.port.mk>
