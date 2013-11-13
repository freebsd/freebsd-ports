# $FreeBSD$

PORTNAME=	deheader
PORTVERSION=	0.8
CATEGORIES=	devel
MASTER_SITES=	http://www.catb.org/esr/deheader/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Tool to find unnecessary includes in C/C++ files

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

NO_BUILD=	yes
USE_PYTHON=	yes

PLIST_FILES=	bin/deheader man/man1/deheader.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/deheader ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/deheader.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
