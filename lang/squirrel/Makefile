PORTNAME=	squirrel
DISTVERSION=	3_1
PORTREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}3/${PORTNAME}%20${PORTVERSION}%20stable
DISTNAME=	${PORTNAME}_${DISTVERSION}_stable

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High level imperative/OO programming language

CONFLICTS=	squsq

USES=		cmake compiler:c++11-lang dos2unix
CMAKE_ARGS=	-DINSTALL_INC_DIR:STRING=include
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}3

.include <bsd.port.mk>
