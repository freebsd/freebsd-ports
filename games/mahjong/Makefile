# ex:ts=8
# New ports collection makefile for:   mahjong
# Date created:                Jan 31, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mahjong
PORTVERSION=	1.3.1
CATEGORIES=	games net
MASTER_SITES=	http://www.stevens-bradfield.com/MahJong/Source/
DISTNAME=	mj-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org

USE_GTK=	yes
USE_GMAKE=	yes
MAKE_ENV=	PERL="${PERL}"

INSTALL_TARGET=	install install.man

MAN1=		xmj.1 mj-player.1 mj-server.1

post-patch:
	@${PERL} -pi -e "s,^CC ,#CC ,g ; \
		s,^PERL,#PERL,g ; \
		s,gtk-config,${GTK_CONFIG},g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
