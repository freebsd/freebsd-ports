# New ports collection makefile for:	Ming
# Date created:		14 October 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ming
PORTVERSION=	0.0.3a
CATEGORIES=	graphics
MASTER_SITES=	http://www.opaque.net/ming/
EXTRACT_SUFX=	.tgz

MAINTAINER=	knu@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME}/src

DOCS=		CHANGES \
		CREDITS \
		Makefile \
		README \
		TODO

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/

.include <bsd.port.mk>
