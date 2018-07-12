# $FreeBSD$

PORTNAME=	nyan
PORTVERSION=	g20180708
CATEGORIES=	lang
PKGNAMESUFFIX=	-lang

MAINTAINER=	martinfilla@post.cz
COMMENT=	Data description language designed for openage

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/legal/LGPLv3

BROKEN_FreeBSD_10=	conflicting types for '__hash_table<_Tp, _Hash, _Equal, _Alloc>'

USES=		cmake:outsource compiler:c++17-lang
USE_GITHUB=	yes
GH_ACCOUNT=	SFTtech
GH_TAGNAME=	3c263e2
USE_LDCONFIG=	yes

.include <bsd.port.mk>
