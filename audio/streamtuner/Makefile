# New ports collection makefile for:	streamtuner
# Date created:			02 Apr 2002
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		streamtuner
PORTVERSION=		0.9.1
CATEGORIES=		audio www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	streamtuner

MAINTAINER=		jylefort@brutele.be
COMMENT=		A GTK+ stream directory browser

LIB_DEPENDS=		gtk-x11-2.0:${PORTSDIR}/x11-toolkits/gtk20 \
			curl:${PORTSDIR}/ftp/curl

USE_X_PREFIX=		yes
GNU_CONFIGURE=		yes

MAN1=			streamtuner.1

.include <bsd.port.mk>
