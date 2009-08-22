# New ports collection makefile for:	gsoap
# Date created:				8 March 2004
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	gsoap
PORTVERSION=	2.7.13
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}2/gSOAP/${PORTVERSION}%20stable
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Generator Tools for Coding SOAP/XML Web Services in C and C++

GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gnometarget

WRKSRC=		${WRKDIR}/${PORTNAME}-2.7

ONLY_FOR_ARCHS=	i386 amd64

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

post-install:
	@${MKDIR} ${PREFIX}/lib/gsoap
	@${CP} ${WRKSRC}/gsoap/stdsoap2.c ${PREFIX}/lib/gsoap
	@${LN} ${PREFIX}/lib/gsoap/stdsoap2.c ${PREFIX}/lib/gsoap/stdsoap2.cpp

.include <bsd.port.post.mk>
