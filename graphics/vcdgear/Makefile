# New ports collection makefile for:	vcdgear
# Date created:	 	06 January 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vcdgear
PORTVERSION=	1.4
CATEGORIES= 	graphics
MASTER_SITES=	http://www.vcdgear.org/files/
DISTFILES=	vcdgear_FreeBSD.gz

MAINTAINER=	cpiazza@FreeBSD.org

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 300004
BROKEN=	'Only an ELF binary is distributed'
.endif

ONLY_FOR_ARCHS=	i386
NO_BUILD=	true
NO_WRKSUBDIR=	true
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/vcdgear

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vcdgear ${PREFIX}/bin

.include <bsd.port.post.mk>
