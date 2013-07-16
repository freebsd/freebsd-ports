# $FreeBSD$

PORTNAME=	cvs
PORTVERSION=	1.20120905
CATEGORIES=	devel
MASTER_SITES=	LOCAL/eadler

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Version control system

LICENSE=	GPLv2

WRKSRC=	${WRKDIR}/call/cvs-build

USE_XZ=	yes

MAN1=	cvs.1
MAN8=	cvsbug.8

MANCOMPRESSED=	yes

INFO=	cvs cvsclient

MAKE_ENV+=	DESTDIR=${PREFIX}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900000
BROKEN=	does not link
.endif

pre-install:
	${MKDIR} ${EXAMPLESDIR}/contrib

.include <bsd.port.post.mk>
