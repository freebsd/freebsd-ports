# $FreeBSD$

PORTNAME=	cvs
PORTVERSION=	1.20120905
CATEGORIES=	devel ipv6
MASTER_SITES=	LOCAL/eadler
PKGNAMESUFFIX=	+ipv6

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	${DISTNAME}-v6-20140105.diff.gz
PATCH_WRKSRC=	${WRKDIR}/call/cvs
PATCH_DIST_STRIP=	-p1

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	IPv6 enabled cvs.  You can use IPv6 connection when using pserver

CONFLICTS=	cvsnt-[12]* cvs-devel-[12]*
LICENSE=	GPLv2

USES=		uidfix
PATCHDIR=	${WRKDIR}/call/cvs-build
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
