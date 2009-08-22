# New ports collection makefile for:	gdt
# Date created:				Sun, Apr 29 2007
# Whom:					Hiroki Sato <hrs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gdt
PORTVERSION=	3.0.2
CATEGORIES=	cad
MASTER_SITES=	SF/gds2/gds2/GDT-${PORTVERSION}
DISTNAME=	${PORTNAME:U}-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	GDS2/GDT format translator

USE_PERL5_RUN=	yes
WRKSRC=		${WRKDIR}/${PORTNAME:U}-${PORTVERSION}
PLIST_FILES=	bin/gdsinfo bin/gds2gdt bin/gdt2gds bin/scalegds

post-patch:
	${REINPLACE_CMD} 's,^#!/usr/bin/perl,#!${PERL},' \
		${WRKSRC}/Examples/gdsinfo \
		${WRKSRC}/Examples/scalegds

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	${INSTALL_SCRIPT} \
		${WRKSRC}/Examples/gdsinfo \
		${WRKSRC}/Examples/scalegds \
		${PREFIX}/bin

.include <bsd.port.mk>
