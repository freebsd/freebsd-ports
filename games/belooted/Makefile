# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	belooted
PORTVERSION=	0.1.4.1
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://boby.joe.free.fr/dev/belooted/files/ \
		LOCAL/martymac

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Popular 32-card trick-taking game played in France

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} '/^LIBS =/s/$$/ -lm/' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
