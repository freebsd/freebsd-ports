# New ports collection makefile for:	nslint
# Date created:		27 October 1997
# Whom:			dglo@ssec.wisc.edu
#
# $FreeBSD$
#

PORTNAME=	nslint
PORTVERSION=	2.1.a3
CATEGORIES=	dns
MASTER_SITES=	ftp://ftp.ee.lbl.gov/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a/a/}

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Perform consistency checks on DNS zone files

GNU_CONFIGURE=	yes
ALL_TARGET=	nslint
INSTALL_TARGET=	install install-man
MAN8=		nslint.8
PLIST_FILES=	bin/nslint

.include <bsd.port.mk>
