# Created by: mat
# $FreeBSD$

PORTNAME=	libphk
PORTVERSION=	0.3.20080902
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://phk.freebsd.dk/phkrel/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=mat
DISTNAME=	Libphk.${PORTVERSION:C/0.3.//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	PHK's utilities functions

USES=	uidfix tar:tgz

WRKSRC=		${WRKDIR}/Libphk

post-patch:
	@${SED} -i -e 's!/usr/local!$${PREFIX}!g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
