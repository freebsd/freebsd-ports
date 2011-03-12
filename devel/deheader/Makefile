# New ports collection makefile for:	deheader
# Date Created:		12 March 2011
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	deheader
PORTVERSION=	0.6
CATEGORIES=	devel
MASTER_SITES=	http://www.catb.org/esr/deheader/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	A tool to find unnecesary includes in C/C++ files

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

NO_BUILD=	yes
USE_PYTHON=	yes

MAN1=		deheader.1

PLIST_FILES=	bin/deheader

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/deheader ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/deheader.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
