# $FreeBSD$

PORTNAME=	opustags
DISTVERSION=	1.3.0
CATEGORIES=	audio

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	0e9c4e2f9d891f738ac2b3bd97a096bfec642ddd.patch:-p1 # Fix the build failure on 11: Define _GNU_SOURCE for BSD compability https://github.com/fmang/opustags/pull/32

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	View and edit Ogg Opus comments

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libogg.so:audio/libogg

USES=		cmake compiler:c++14-lang iconv pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	fmang

PLIST_FILES=	bin/opustags \
		man/man1/opustags.1.gz

.include <bsd.port.mk>
