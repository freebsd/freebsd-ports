# $FreeBSD$

PORTNAME=	yajl
PORTVERSION=	2.1.0
CATEGORIES=	devel

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Portable JSON parsing and serialization library in ANSI C

LICENSE=	ISCL

USE_GITHUB=	yes
GH_ACCOUNT=	lloyd
GH_COMMIT=	66cb08c

USE_LDCONFIG=	yes
USES=		cmake:outsource

PLIST_SUB=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e "s,share/pkgconfig,libdata/pkgconfig,g" \
		${WRKSRC}/src/CMakeLists.txt

.include <bsd.port.mk>
