# New ports collection makefile for:   gbe
# Date created:        16 April 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gbe
PORTVERSION=	0.0.22
CATEGORIES=	emulators
MASTER_SITES=	http://www.zophar.net/unix/Files/

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_X_PREFIX=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gbe ${PREFIX}/bin

.include <bsd.port.mk>
