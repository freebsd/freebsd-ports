# New ports collection makefile for:	mpmf20
# Version required:	1.01
# Date created:		22 September 1999
# Whom:			Markus Holmberg <saska@acc.umu.se>
#
# $FreeBSD$
#

DISTNAME=	mpmf20
PKGNAME=	mpmf20-1.01
CATEGORIES=	audio
MASTER_SITES=	http://www.world.co.uk/sba/ \
		http://www.acc.umu.se/~markush/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

MAKEFILE=	makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mpmf20 ${PREFIX}/bin

.include <bsd.port.mk>
