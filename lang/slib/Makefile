# New ports collection makefile for:   slib
# Date created:        01 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	slib
PORTVERSION=	2c7
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	scm

MAINTAINER=	nakai@FreeBSD.org
DISTNAME=	slib2c7

BUILD_DEPENDS=	scheme48:${PORTSDIR}/lang/scheme48

WRKSRC=		${WRKDIR}/slib

USE_ZIP=	yes
ALL_TARGET=	slib48
INSTALL_TARGET=	install48

post-install:
	# 	moved here from author's makefile
	${TOUCH} -r ${WRKSRC}/slibcat ${PREFIX}/lib/scheme48/slibcat
	${MKDIR} ${PREFIX}/share/slib
	${INSTALL_DATA} ${WRKSRC}/*.scm ${PREFIX}/share/slib

.include <bsd.port.mk>
