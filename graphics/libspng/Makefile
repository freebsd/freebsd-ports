PORTNAME=	libspng
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.3
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple PNG decoding and encoding library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	randy408
USE_LDCONFIG=	yes

MESON_ARGS=	-Denable_opt=false
PLIST_SUB=	SOVERSION=${DISTVERSION}

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
