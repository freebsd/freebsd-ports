# New ports collection makefile for:	xvmahjongg
# Date created:				21 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xvmahjongg
PORTVERSION=	2.1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.x.org/R5contrib/ \
		ftp://ftp.freesoftware.com/pub/X11/R5contrib/
DISTFILES=	${PORTNAME}${PORTVERSION}.tar.Z

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview

ALL_TARGET=	mahjongg.swap
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/mahjongg2.1
MAN6=		xvmahjongg.6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mahjongg ${PREFIX}/bin/xvmahjongg
	${INSTALL_MAN} ${WRKSRC}/mahjongg.6 ${PREFIX}/man/man6/xvmahjongg.6
	@${MKDIR} ${PREFIX}/share/doc/xvmahjongg
.if !defined(NOPORTDOCS)
.for file in Notes README README.too
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/xvmahjongg
.endfor
.endif

.include <bsd.port.mk>
