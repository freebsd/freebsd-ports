# $FreeBSD$

PORTNAME=	deheader
PORTVERSION=	0.7
CATEGORIES=	devel
MASTER_SITES=	http://www.catb.org/esr/deheader/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Tool to find unnecessary includes in C/C++ files

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
