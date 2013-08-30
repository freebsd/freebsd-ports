# Created by: Vanilla I. Shu <vanilla@MinJe.com.TW>
# $FreeBSD$

PORTNAME=	amp
PORTVERSION=	0.7.6
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	http://www-users.cs.umn.edu/~wburdick/ftp/

MAINTAINER=	delphus@gmail.com
COMMENT=	Another mp3 player

GNU_CONFIGURE=	yes
USES=		gmake

MAN1=		amp.1
PLIST_FILES=	bin/amp

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/amp ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/amp.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
