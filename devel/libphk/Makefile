# New ports collection Makefile for:	Libphk
# Date created:		2 September 2008
# Whom:			mat
#
# $FreeBSD$
#

PORTNAME=	libphk
PORTVERSION=	0.3.20080902
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://phk.freebsd.dk/phkrel/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=mat
DISTNAME=	Libphk.${PORTVERSION:C/0.3.//}
EXTRACT_SUFX=	.tgz

MAINTAINER=	perl@FreeBSD.org
COMMENT=	PHK's utilities functions

WRKSRC=		${WRKDIR}/Libphk

MAN3=	libphk.3 phk_argv.3 phk_binheap.3
MANCOMPRESSED=	yes

post-patch:
	@${SED} -i -e 's!/usr/local!$${PREFIX}!g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
