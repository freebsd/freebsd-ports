# $FreeBSD$

PORTNAME=	tarantool-c
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C client for Tarantool 1.6+

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmsgpuck.so:devel/msgpuck

USES=		cmake compiler

CMAKE_OFF=	ENABLE_BUNDLED_DOCS ENABLE_BUNDLED_MSGPUCK

USE_GITHUB=	yes
GH_ACCOUNT=	tarantool
GH_TAGNAME=	0df3623

post-patch:
	@${GREP} -lr 'msgpuck/msgpuck.h' ${WRKSRC}/ | ${XARGS} ${REINPLACE_CMD} -e 's|msgpuck/msgpuck.h|msgpuck.h|'
	@${REINPLACE_CMD} -e 's|libmsgpuck.a|libmsgpuck.so|' ${WRKSRC}/cmake/FindMsgPuck.cmake

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
EXTRA_PATCHES+= ${FILESDIR}/extra-patch-tnt_CMakeLists.txt
.endif

.include <bsd.port.post.mk>
