# $FreeBSD$

PORTNAME=	deheader
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.catb.org/esr/deheader/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to find unnecessary includes in C/C++ files

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python shebangfix
SHEBANG_FILES=	${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/deheader man/man1/deheader.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/deheader ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/deheader.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
