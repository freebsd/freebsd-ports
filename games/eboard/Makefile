# New ports collection makefile for:	eboard
# Date created:				22 June 2001
# Whom:					petef@databits.net
#
# $FreeBSD$
#

PORTNAME=	eboard
PORTVERSION=	0.3.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	petef@databits.net

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
USE_GTK=	yes
USE_IMLIB=	yes
USE_X_PREFIX=	yes

INSTALL_TARGET=	install install-man

MAN1=	eboard-config.1 eboard-addtheme.1
MAN6=	eboard.6

post-patch:
	@${PERL} -pi -e 's!CXXFLAGS=-O6\n!!' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.for file in Crafty.txt FICS-Timeseal.txt GNUChess4.txt GNUChess5.txt \
	Scripts.txt Sjeng.txt Themes.txt
	${INSTALL_DATA} ${WRKSRC}/Documentation/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
