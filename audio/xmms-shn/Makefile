# New ports collection makefile for:   shntool
# Date created:        2 November 2000
# Whom:                Bill Fenner <fenner@FreeBSD.Org>
#
# $FreeBSD$
#

PORTNAME=	xmms-shn
PORTVERSION=	2.4.0
CATEGORIES=	audio
MASTER_SITES=	http://www.etree.org/shnutils/xmms-shn/source/

MAINTAINER=	naddy@FreeBSD.Org
COMMENT=	XMMS plugin to allow playing shorten-compressed audio

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_INC_LIBTOOL_VER=13

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
