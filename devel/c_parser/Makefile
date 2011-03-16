# ex:ts=8
# Ports collection makefile for:	c_parser
# Date created:			Jan 18, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	c_parser
PORTVERSION=	0.2.5
CATEGORIES=	devel
MASTER_SITES=	http://www.mazumdar.demon.co.uk/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C99 Parser

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/c_parser

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/c_parser ${PREFIX}/bin

.include <bsd.port.mk>
