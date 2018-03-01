# $FreeBSD$

PORTNAME=	tarantool-c
PORTVERSION=	1.0.1
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C client for Tarantool 1.6+

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libmsgpuck.so:devel/msgpuck

CMAKE_OFF=	ENABLE_BUNDLED_MSGPUCK
USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	tarantool
GH_TAGNAME=	7bb49a1

post-patch:
	@${GREP} -lr 'msgpuck/msgpuck.h' ${WRKSRC}/ | ${XARGS} ${REINPLACE_CMD} -e 's|msgpuck/msgpuck.h|msgpuck.h|'

.include <bsd.port.mk>
