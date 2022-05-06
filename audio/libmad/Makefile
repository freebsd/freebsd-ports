# Created by: Sergey Akifyev <asa@gascom.ru>

PORTNAME=	libmad
DISTVERSION=	0.16.0
CATEGORIES=	audio

PATCH_SITES=	https://github.com/tenacityteam/libmad/commit/
PATCHFILES=	c2eb5e1a728c973ea3f957d4cb6e04d77f745568.patch:-p1 \
		a8ca654e3666f442805d93722290bb218b633428.patch:-p1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Libmad library (part of MAD project)

LICENSE=	GPLv2

USES=		cmake cpe pathfix
CPE_VENDOR=	underbit

USE_GITHUB=	yes
GH_ACCOUNT=	tenacityteam
GH_TAGNAME=	15d1ef05

USE_LDCONFIG=	yes

.include <bsd.port.mk>
