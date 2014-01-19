# Created by: trociny
# $FreeBSD$

PORTNAME=	bmkdep
PORTVERSION=	20140112
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Construct Makefile dependency list

MAKE_ENV=	PKGDIR="${PKGDIR}" NO_OBJ=YES

PLIST_FILES=	bin/bmkdep man/man1/bmkdep.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bmkdep ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bmkdep.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
