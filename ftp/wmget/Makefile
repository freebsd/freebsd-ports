# Created by: Ulrich Spoerlein <uspoerlein@gmail.com>
# $FreeBSD$

PORTNAME=	wmget
PORTVERSION=	0.6.0
PORTREVISION=	6
CATEGORIES=	ftp
MASTER_SITES=	http://amtrickey.net/download/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	uqs
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	uqs@FreeBSD.org
COMMENT=	Dock app for Window Maker providing wget functionality

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_XORG=	x11 xpm
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_ENV+=	${CONFIGURE_ENV}

MAN1=		wmget.1
PLIST_FILES=	bin/wmget

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmget ${PREFIX}/bin
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/wmget.1 ${PREFIX}/man/man1
.endif

.include <bsd.port.mk>
