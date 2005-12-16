# New ports collection makefile for:	virt
# Date created:			8 May 2001
# Whom:				lg
#
# $FreeBSD$

PORTNAME=	virt
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Game and keyboard teacher in one. Enjoy it!

DEPRECATED=	mastersite disappeared, no longer maintained by author
EXPIRATION_DATE=2006-02-15

USE_GNOME=	gtk12
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} `gtk12-config --cflags`"
MAN6=		virt.6
MANCOMPRESSED=	no

do-install:
	@${MKDIR} ${PREFIX}/share/${PORTNAME}/keytop
	${INSTALL_PROGRAM} ${WRKSRC}/virt ${PREFIX}/bin
	(cd ${WRKSRC} && ${INSTALL_DATA} virtrc virt.eng virt.rus COPYRIGHT ${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/keytop/*.xpm ${DATADIR}/keytop
	${INSTALL_MAN} ${WRKSRC}/virt.6 ${PREFIX}/man/man6

.include <bsd.port.mk>
