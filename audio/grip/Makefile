# New ports collection makefile for:	grip
# Date created:				31 May 2000
# Whom:					kbyanc@posi.net
#
# $FreeBSD$
#

PORTNAME=	grip
PORTVERSION=	2.94
CATEGORIES=	audio
MASTER_SITES=	http://www.nostatic.org/grip/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_GMAKE=	yes
ALL_TARGET=	gripnopar

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/grip ${PREFIX}/bin

.include <bsd.port.mk>
