# New ports collection makefile for:	gdt
# Date created:				Sun, Apr 29 2007
# Whom:					Hiroki Sato <hrs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gdt
PORTVERSION=	1.0.1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gds2
DISTNAME=	${PORTNAME:U}_${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	GDS2/GDT format translator

USE_PERL5_RUN=	yes
WRKSRC=		${WRKDIR}/${PORTNAME:U}-${PORTVERSION}
PLIST_FILES=	bin/gdsinfo bin/gds2gdt bin/gdt2gds

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Examples/gdsinfo ${PREFIX}/bin

.include <bsd.port.mk>
