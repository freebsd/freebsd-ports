# New ports collection makefile for:	nslint
# Date created:		27 October 1997
# Whom:			dglo@ssec.wisc.edu
#
# $FreeBSD$
#

PORTNAME=	nslint
PORTVERSION=	2.0.2a2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ee.lbl.gov/

MAINTAINER=	petef@databits.net

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--quiet --mandir=${MANPREFIX}/man --prefix=${PREFIX}
ALL_TARGET=	nslint
INSTALL_TARGET=	install install-man
MAN8=		nslint.8

.include <bsd.port.mk>
