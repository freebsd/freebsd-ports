PORTNAME=	stc
DISTVERSIONPREFIX=	v
DISTVERSION=	5.0
CATEGORIES=	devel
PKGNAMESUFFIX=	-library

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Modern, user-friendly, generic, type-safe and fast C99 library
WWW=		https://github.com/stclib/STC/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		meson
USE_GITHUB=	yes
GH_ACCOUNT=	stclib
GH_PROJECT=	STC
USE_LDCONFIG=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES STATIC
OPTIONS_SUB=	yes

DOCS_MESON_ENABLED=	docs
DOCS_MESON_ON=		-Ddocsdir=${DOCSDIR}
EXAMPLES_MESON_ENABLED=	examples
EXAMPLES_MESON_ON=	-Dexamplesdir=${EXAMPLESDIR}
STATIC_MESON_ON=	-Ddefault_library=both
STATIC_MESON_OFF=	-Ddefault_library=shared

.include <bsd.port.mk>
