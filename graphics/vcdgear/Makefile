# New ports collection makefile for:	vcdgear
# Version required:	1.4
# Date created:	 	06 January 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	vcdgear_FreeBSD
PKGNAME=	vcdgear-1.4
CATEGORIES= 	graphics
MASTER_SITES=	http://www.vcdgear.org/files/
EXTRACT_SUFX=	.gz

MAINTAINER=	cpiazza@FreeBSD.org

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 300004
BROKEN=	'Only an ELF binary is distributed'
.endif

ONLY_FOR_ARCHS=	i386
NO_BUILD=	true
WRKSRC=		${WRKDIR}
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/vcdgear

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vcdgear ${PREFIX}/bin

.include <bsd.port.post.mk>
