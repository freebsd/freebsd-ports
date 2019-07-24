# $FreeBSD$

PORTNAME=		janet
DISTVERSIONPREFIX=	v
DISTVERSION=		1.1.0
CATEGORIES=		lang

MAINTAINER=		dch@FreeBSD.org
COMMENT=		Functional embeddable lisp with C interop, & performant data types

LICENSE=		MIT
LICENSE_FILE=		${WRKSRC}/LICENSE

USES=			meson
USE_LDCONFIG=		yes
USE_GITHUB=		yes
GH_ACCOUNT=		janet-lang

MESON_ARGS=		-DJANET_BUILD='\"release\"'

.include <bsd.port.mk>
