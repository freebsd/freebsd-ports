PORTNAME=	sratom
DISTVERSION=	0.6.20
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Library for serialising LV2 atoms to/from RDF
WWW=		https://drobilla.net/software/sratom.html

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>=1.14.0:audio/lv2
LIB_DEPENDS=	libserd-0.so:devel/serd \
		libsord-0.so:devel/sord
RUN_DEPENDS=	lv2>=1.14.0:audio/lv2

USES=		meson pkgconfig python:build tar:xz
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION=${DISTVERSION}
MESON_ARGS+=	-Ddocs=disabled

.include <bsd.port.mk>
