# New ports collection makefile for:	mpmf20
# Date created:		22 September 1999
# Whom:			Markus Holmberg <saska@acc.umu.se>
#
# $FreeBSD$
#

PORTNAME=	mpmf20
PORTVERSION=	1.01
CATEGORIES=	audio
MASTER_SITES=	http://www.world.co.uk/sba/ \
		http://www.acc.umu.se/~markush/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	File transfer tool for the MPMan MP-F20 portable MP3-player

MAKEFILE=	makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mpmf20 ${PREFIX}/bin

.include <bsd.port.mk>
