# New ports collection makefile for:	gsoap
# Date created:				8 March 2004
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	gsoap
PORTVERSION=	2.7.9e
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gsoap2
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Generator Tools for Coding SOAP/XML Web Services in C and C++

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

WRKSRC=		${WRKDIR}/${PORTNAME}-2.7

ONLY_FOR_ARCHS=	i386 amd64

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
CONST=
.else
CONST=	const
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/> FD_SETSIZE/>= (int)FD_SETSIZE/g' ${WRKSRC}/soapcpp2/stdsoap2.c
	@${REINPLACE_CMD} -e 's/> FD_SETSIZE/>= (int)FD_SETSIZE/g' ${WRKSRC}/soapcpp2/stdsoap2.cpp
	@${REINPLACE_CMD} -e 's/%%CONST%%/${CONST}/' ${WRKSRC}/soapcpp2/stdsoap2.cpp

.include <bsd.port.post.mk>
