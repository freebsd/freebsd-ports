# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	squirrel
DISTVERSION=	3_1
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}3/${PORTNAME}%20${PORTVERSION}%20stable
DISTNAME=	${PORTNAME}_${DISTVERSION}_stable

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High level imperative/OO programming language

CONFLICTS=	squsq-[0-9]*

BROKEN_powerpc64=	fails to compile: cc1plus: error: unrecognized command line option -std=c++0x

USES=		cmake dos2unix
CMAKE_ARGS=	-DINSTALL_INC_DIR:STRING=include
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}3

.include <bsd.port.mk>
