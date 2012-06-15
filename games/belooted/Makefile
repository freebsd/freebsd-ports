# New ports collection makefile for:	belooted
# Date created:				1 August 2007
# Whom:					Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	belooted
PORTVERSION=	0.1.4.1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://boby.joe.free.fr/dev/belooted/files/ \
		LOCAL/martymac

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	A popular 32-card trick-taking game played in France

LICENSE=	GPLv2

USE_GNOME=	gtk20 desktopfileutils
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README TODO

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
	@-update-desktop-database
.endif

.include <bsd.port.mk>
