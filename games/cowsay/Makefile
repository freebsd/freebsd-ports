# New ports collection makefile for:	cowsay
# Date created:		01 Sep 2000
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cowsay
PORTVERSION=	3.03
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.nog.net/pub/tony/cowsay/

MAINTAINER=	kris@FreeBSD.org

USE_PERL5=	yes

NO_BUILD=	# defined

MAN1=		cowsay.1

do-install:
	cd ${WRKSRC}; ${SH} install.sh ${PREFIX}

.include <bsd.port.mk>
