PORTNAME=	deheader
DISTVERSION=	1.10
CATEGORIES=	devel
MASTER_SITES=	http://www.catb.org/esr/${PORTNAME}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Tool to find unnecessary includes in C/C++ files
WWW=		http://www.catb.org/esr/deheader/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xmlto:textproc/xmlto

USES=		python shebangfix
SHEBANG_FILES=	${PORTNAME}

NO_ARCH=	yes

PLIST_FILES=	bin/deheader \
		share/man/man1/deheader.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/deheader ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/deheader.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
