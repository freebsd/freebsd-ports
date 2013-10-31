# $FreeBSD$

PORTNAME=	cvs
PORTVERSION=	1.20120905
CATEGORIES=	devel
MASTER_SITES=	LOCAL/eadler

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Version control system

LICENSE=	GPLv2

USES=		uidfix
WRKSRC=		${WRKDIR}/call/cvs-build
USE_XZ=		yes
INFO=		cvs cvsclient

# bsd.stage.makes sets the wrong value for DESTDIR
DESTDIRNAME=	NADA
MAKE_ARGS=	DESTDIR=${STAGEDIR}${PREFIX}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900000
BROKEN=	does not link
.endif

pre-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/contrib

.include <bsd.port.post.mk>
