# $FreeBSD$

PORTNAME=	libpru
PORTVERSION=	0.4
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/rpaulo/libpru/get/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to interface with PRUs

LICENSE=	BSD2CLAUSE

IGNORE_DragonFly=	only supported on FreeBSD
USES=		cmake compiler

WRKSRC=		${WRKDIR}/rpaulo-libpru-5a74157b82b8

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's/ -Weverything//'  ${WRKSRC}/CMakeLists.txt
.if ${CHOSEN_COMPILER_TYPE} == gcc
	${REINPLACE_CMD} -e 's/ -Werror//'  ${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.post.mk>
