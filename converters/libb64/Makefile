# Created by: Ismail Yenigul <ismail.yenigul@surgate.com>
# $FreeBSD$

PORTNAME=	libb64
PORTVERSION=	1.2
CATEGORIES=	converters mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	ismail.yenigul@surgate.com
COMMENT=	A library of ANSI C routines for fast encoding/decoding data

BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_ZIP=	yes
USE_GMAKE=	yes

NO_STAGE=	yes
do-install:
	${INSTALL_DATA} ${WRKSRC}/src/libb64.a ${PREFIX}/lib
	${MKDIR} ${PREFIX}/include/b64
	${INSTALL_DATA} ${WRKSRC}/include/b64/*.h ${PREFIX}/include/b64

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

.include <bsd.port.post.mk>
