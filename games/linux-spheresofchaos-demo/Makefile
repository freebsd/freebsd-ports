# Created by: Peter Pentchev <roam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spheresofchaos
PORTVERSION=	2.06
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=	http://people.FreeBSD.org/~roam/games/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	roam
PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	-demo
DISTNAME=	chaosl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An unusual and spectacular shoot-em-up for the PC

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2014-03-10

USES=		zip
USE_LINUX=	yes
USE_LINUX_APPS=	sdl12

NO_BUILD=	yes

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/Chaosl ${PREFIX}/bin
	${BRANDELF} -t Linux ${PREFIX}/bin/Chaosl

.include <bsd.port.mk>
