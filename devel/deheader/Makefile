# $FreeBSD$

PORTNAME=	deheader
PORTVERSION=	1.6
CATEGORIES=	devel

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Tool to find unnecessary includes in C/C++ files

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xmlto:textproc/xmlto

USES=		python shebangfix tar:bz2
SHEBANG_FILES=	${PORTNAME}
NO_ARCH=	yes

USE_GITLAB=	yes
GL_ACCOUNT=	esr
GL_COMMIT=	b408c9013f4e1d917cc12f06edda4e1782e64888

PLIST_FILES=	bin/deheader man/man1/deheader.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/deheader ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/deheader.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
