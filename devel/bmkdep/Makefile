PORTNAME=	bmkdep
PORTVERSION=	20140112
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Construct Makefile dependency list
WWW=		https://netbsd.org

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	trociny

USES=		uidfix
MAKE_ENV=	PKGDIR="${PKGDIR}" NO_OBJ=YES

PLIST_FILES=	bin/bmkdep share/man/man1/bmkdep.1.gz

.include <bsd.port.mk>
