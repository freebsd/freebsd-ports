PORTNAME=	cdecl
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	18.5
CATEGORIES=	devel

MAINTAINER=	ler@FreeBSD.org
COMMENT=	Explains complicated C/C++ declarations in plain English
WWW=		https://github.com/paul-j-lucas/cdecl/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	flex:textproc/flex

USES=		autoreconf bison ncurses readline
USE_GITHUB=	yes
GH_ACCOUNT=	paul-j-lucas

GNU_CONFIGURE=	yes

CONFLICTS=	cutils

.include <bsd.port.mk>
