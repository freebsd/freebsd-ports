# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	epos
PORTVERSION=	2.5.37
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-dev/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text-to-Speech system

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	multi

USES=		bison gmake
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_lib_stdcpp_main=no

post-patch:
	@${REINPLACE_CMD} -e 's/^\(SUBDIRS =.*\)doc/\1/' ${WRKSRC}/Makefile.in
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-ggdb||'
	@${REINPLACE_CMD} -e 's|<iostream.h>|<iostream>|' \
		${WRKSRC}/src/nnet/neural.cc

.include <bsd.port.mk>
