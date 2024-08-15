PORTNAME=	scc
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.5
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	LOC counter with COCOMO and complexity estimation
WWW=		https://github.com/boyter/scc

LICENSE=		MIT UNLICENSE
LICENSE_COMB=		dual
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE
LICENSE_FILE_UNLICENSE=	${WRKSRC}/UNLICENSE

USES=		go:modules
GO_MODULE=	github.com/boyter/scc/v3

PLIST_FILES=	bin/scc

.include <bsd.port.mk>
