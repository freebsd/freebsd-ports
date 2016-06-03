# Created by: Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	gma
PORTVERSION=	0.6
CATEGORIES=	games
MASTER_SITES=	http://www.student.nada.kth.se/~d92-jwa/code/gma/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Go-moku game which learns playing the game from studying its opponent

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

LICENSE=	GPLv2+

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/apprentice.gmaplayer bin/gma-console

post-patch:
	@${REINPLACE_CMD} -e \
		's|stl\.h|map| ; \
		 s|^CXXFLAGS|#CXXFLAGS|' ${WRKSRC}/configure

.include <bsd.port.mk>
