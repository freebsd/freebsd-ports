PORTNAME=	fileobj
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.108
CATEGORIES=	editors

MAINTAINER=	zrj@dragonflybsd.org
COMMENT=	Portable hex editor with vi like interface

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	kusumi
USE_PYTHON=	autoplist concurrent distutils optsuffix

PLIST_FILES=	man/man1/fileobj.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/fileobj.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
