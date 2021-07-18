PORTNAME=	janet
DISTVERSIONPREFIX=	v
DISTVERSION=	1.16.1
CATEGORIES=	lang

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
