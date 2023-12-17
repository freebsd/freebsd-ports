PORTNAME=	cdecl
PORTVERSION=	15.0
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	devel

MAINTAINER=	ler@FreeBSD.org
COMMENT=	Explains complicated C/C++ declarations in plain English
WWW=		https://github.com/paul-j-lucas/cdecl

LICENSE=	GPLv3

BUILD_DEPENDS=	flex:textproc/flex

USES=		autoreconf bison ncurses readline

CONFLICTS=	cutils

USE_GITHUB=	yes

GH_ACCOUNT=	paul-j-lucas

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/cdecl bin/c++decl man/man1/cdecl.1.gz man/man1/c++decl.1.gz

.include <bsd.port.mk>
