# $FreeBSD$

PORTNAME=	vtable-dumper
PORTVERSION=	1.1
CATEGORIES=	devel

MAINTAINER=	pi@FreeBSD.org
COMMENT=	List content of virtual tables in a C++ shared library

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	lvc
PLIST_FILES=	bin/vtable-dumper

do-install:
	${INSTALL} -s ${WRKSRC}/vtable-dumper ${STAGEDIR}${PREFIX}/bin/vtable-dumper

.include <bsd.port.mk>
