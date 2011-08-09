# New ports collection makefile for:    epos-devel
# Date created:         3 September 2005
# Whom:                 Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	epos
PORTVERSION=	2.5.37
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-dev/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text-to-Speech system

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/doc/COPYING
LICENSE_FILE_LGPL20=	${WRKSRC}/libs/regex/COPYING.LIB

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

post-patch:
	${REINPLACE_CMD} -e 's/^\(SUBDIRS =.*\)doc/\1/' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
