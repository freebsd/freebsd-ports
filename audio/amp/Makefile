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

PLIST_FILES=	bin/amp \
		man/man1/amp.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/amp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/amp.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
