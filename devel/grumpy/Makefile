# $FreeBSD$

PORTNAME=	grumpy
PORTVERSION=	0.0.0.2017020301
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Python to Go source code transcompiler and runtime

BUILD_DEPENDS=	go:lang/go python:lang/python
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TAGNAME=	348f038

USES=		gmake python

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
PLIST_SUB=	ARCH=amd64
.endif
.if ${ARCH} == "i386"
PLIST_SUB=	ARCH=386
.endif

do-install:
	cd ${WRKSRC}/build/pkg && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/go/pkg/
	cd ${WRKSRC}/build/src && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/go/src/
	cd ${WRKSRC}/build/lib/python${PYTHON_VER}/site-packages && ${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR}
.for bin in benchcmp coverparse diffrange grumpc
	${INSTALL_PROGRAM} ${WRKSRC}/build/bin/${bin} ${STAGEDIR}${PREFIX}/bin/
.endfor

.include <bsd.port.mk>
