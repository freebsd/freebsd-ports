# Created by: gahr
# $FreeBSD$

PORTNAME=	io
PORTVERSION=	20180807
PORTREVISION=	1
CATEGORIES=	lang
PKGNAMESUFFIX=	-devel

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Small prototype-based programming language (devel version)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

CONFLICTS=	io-[0-9]*

USES=		cmake:noninja compiler:c11

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	IoLanguage
GH_TAGNAME=	9bfac31d

GH_TUPLE+=	kgabis:parson:4f3eaa6:parson/deps/parson

MAKE_JOBS_UNSAFE=	yes

CMAKE_ARGS=	-DWITHOUT_EERIE:BOOL=ON

.include <bsd.port.pre.mk>

# disable sse on non-x86 archs
.if ${ARCH} != amd64 && ${ARCH} != i386
EXTRA_PATCHES+= ${PATCHDIR}/extra-patch-CMakeLists.txt
.endif

.include <bsd.port.post.mk>
