# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	epos
PORTVERSION=	2.5.37
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-dev/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Language independent Text-to-Speech (TTS) system

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	multi

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	YACC="${YACC}"

post-patch:
	@${REINPLACE_CMD} -e 's/^\(SUBDIRS =.*\)doc/\1/' ${WRKSRC}/Makefile.in
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-ggdb||'
	@${REINPLACE_CMD} -e 's|<iostream.h>|<iostream>|' \
		${WRKSRC}/src/nnet/neural.cc

.include <bsd.port.mk>
