PORTNAME=	fileobj
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.6
PORTREVISION=	1
CATEGORIES=	editors

MAINTAINER=	tkusumi@netbsd.org
COMMENT=	Portable hex editor with vi like interface
WWW=		https://github.com/kusumi/fileobj

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	kusumi
USE_PYTHON=	autoplist concurrent distutils optsuffix

PLIST_FILES=	share/man/man1/fileobj.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/fileobj.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
