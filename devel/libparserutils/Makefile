# Created by: David Romano <unobe@cpan.org>
# $FreeBSD$

PORTNAME=	libparserutils
PORTVERSION=	0.2.4
CATEGORIES=	devel
MASTER_SITES=	http://download.netsurf-browser.org/libs/releases/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lexer/parser utility functions for NetSurf

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	netsurf-buildsystem>=1.5:devel/netsurf-buildsystem

USES=		gmake iconv localbase pkgconfig
USE_LDCONFIG=	yes

MAKE_ENV=	COMPONENT_TYPE="lib-shared"
LDFLAGS+=	${ICONV_LIB}

PLIST_SUB=	VERSION=${PORTVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libparserutils.so

.include <bsd.port.mk>
