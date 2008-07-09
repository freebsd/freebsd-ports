# New ports collection makefile for:	gsoap
# Date created:				8 March 2004
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	gsoap
PORTVERSION=	2.7.10
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gsoap2
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Generator Tools for Coding SOAP/XML Web Services in C and C++

GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gnometarget

WRKSRC=		${WRKDIR}/${PORTNAME}-2.7

ONLY_FOR_ARCHS=	i386 amd64

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
IGNORE=	does not compile: needs gethostbyname_r()
.endif

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

post-install:
	@${MKDIR} ${PREFIX}/lib/gsoap
	@${CP} ${WRKSRC}/gsoap/stdsoap2.c ${PREFIX}/lib/gsoap
	@${LN} ${PREFIX}/lib/gsoap/stdsoap2.c ${PREFIX}/lib/gsoap/stdsoap2.cpp

.include <bsd.port.post.mk>
