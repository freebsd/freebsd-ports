# New ports collection makefile for:	libhoard
# Date created:			May 24, 2003
# Whom:				Sergey A. Osokin <osa@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libhoard
PORTVERSION=	2.1.2d
PORTREVISION?=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.cs.umass.edu/~emery/software/

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Fast, scalable and memory-efficient allocator for MP

USE_GMAKE=	yes
MAKE_ENV=	USE_FREEBSD=1 \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
INSTALLS_SHLIB=	YES

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 501100
IGNORE=		"You must have a FreeBSD 5.1-RELEASE or better"
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/libhoard.so ${PREFIX}/lib/libhoard.so.1
	${LN} -sf ${PREFIX}/lib/libhoard.so.1 ${PREFIX}/lib/libhoard.so
.if !defined(NOPORTDOCS)
	${INSTALL} -d -m 0755 ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/asplos2000.pdf ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
