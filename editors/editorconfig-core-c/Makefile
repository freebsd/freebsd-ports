PORTNAME=	editorconfig-core-c
PORTVERSION=	0.12.5
DISTVERSIONPREFIX=	v
CATEGORIES=	editors

MAINTAINER=	ports@FreeBSD.org
COMMENT=	EditorConfig core library and executable written in C

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	doxygen:devel/doxygen
LIB_DEPENDS=	libpcre2-8.so:devel/pcre2

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	editorconfig

USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	py*-editorconfig

PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		SHLIB_MAJOR=${PORTVERSION:C/\..+//} \
		SHLIB_VER=${PORTVERSION}

.include <bsd.port.mk>
