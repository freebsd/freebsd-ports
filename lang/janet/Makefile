# $FreeBSD$

PORTNAME=	janet
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.0
CATEGORIES=	lang

PATCH_SITES=	https://github.com/janet-lang/janet/commit/
PATCHFILES=	7275370ae563e8bfa7e907c9931bb1e0c88686d3.patch:-p1

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Functional embeddable lisp with C interop, & performant data types

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		meson
USE_GITHUB=	yes
GH_ACCOUNT=	janet-lang
USE_LDCONFIG=	yes

PLIST_SUB=	SOVERSION=${DISTVERSION} \
		SOVERSION_R=${DISTVERSION:R}

.include <bsd.port.mk>
