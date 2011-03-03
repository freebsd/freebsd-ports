# New ports collection makefile for:	cowsay
# Date created:		01 Sep 2000
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cowsay
PORTVERSION=	3.03
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.nog.net/~tony/warez/

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Configurable talking characters in ASCII art

USE_PERL5=	yes

NO_BUILD=	# defined

MAN1=		cowsay.1
MLINKS=		cowsay.1 cowthink.1

do-install:
	cd ${WRKSRC}; ${SH} install.sh ${PREFIX}
	@${INSTALL_DATA} ${FILESDIR}/box.cow ${PREFIX}/share/cows
	@${INSTALL_DATA} ${FILESDIR}/jkh.cow ${PREFIX}/share/cows
	@${INSTALL_DATA} ${FILESDIR}/tux-stab.cow ${PREFIX}/share/cows

.include <bsd.port.mk>
