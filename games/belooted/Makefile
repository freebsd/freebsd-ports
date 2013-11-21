# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	belooted
PORTVERSION=	0.1.4.1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://boby.joe.free.fr/dev/belooted/files/ \
		LOCAL/martymac

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	A popular 32-card trick-taking game played in France

LICENSE=	GPLv2

USES=		gmake pkgconfig desktop-file-utils
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README TODO

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
