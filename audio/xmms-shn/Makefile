# New ports collection makefile for:   shntool
# Date created:        2 November 2000
# Whom:                Bill Fenner <fenner@FreeBSD.Org>
#
# $FreeBSD$
#

PORTNAME=	xmms-shn
PORTVERSION=	2.2.5
CATEGORIES=	audio
MASTER_SITES=	http://shnutils.etree.org/xmms-shn/source/

MAINTAINER=	fenner@FreeBSD.Org

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/audio/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/audio/xmms

USE_X_PREFIX=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif #NOPORTDOCS

.include <bsd.port.mk>
