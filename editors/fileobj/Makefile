# Created by: Rimvydas Jasinskas <zrj@ef.irc>
# $FreeBSD$

PORTNAME=	fileobj
PORTVERSION=	0.7.55
DISTVERSIONPREFIX=	v
CATEGORIES=	editors

MAINTAINER=	zrj@dragonflybsd.org
COMMENT=	Portable hex editor with vi like interface

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

GH_ACCOUNT=	kusumi
USE_GITHUB=	yes

USES=		python
USE_PYTHON=	autoplist distutils concurrent optsuffix

PLIST_FILES=	man/man1/fileobj.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/fileobj.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
