# New ports collection makefile for:	wmget
# Date created:				05.01.2004
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$

PORTNAME=	wmget
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	http://amtrickey.net/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	q@uni.de
COMMENT=	Dock app for Window Maker providing wget functionality

LIB_DEPENDS=	curl.2:${PORTSDIR}/ftp/curl

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GETOPT_LONG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_ENV+=	${CONFIGURE_ENV}

MAN1=		wmget.1
PLIST_FILES=	bin/wmget

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmget ${PREFIX}/bin
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/wmget.1 ${PREFIX}/man/man1
.endif

.include <bsd.port.mk>
