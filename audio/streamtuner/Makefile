# New ports collection makefile for:	streamtuner
# Date created:			02 Apr 2002
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		streamtuner
PORTVERSION=		0.10.0
CATEGORIES=		audio www
MASTER_SITES=		http://savannah.nongnu.org/download/streamtuner/streamtuner.pkg/${PORTVERSION}/

MAINTAINER=		jylefort@brutele.be
COMMENT=		A GTK+ stream directory browser

USE_GNOME=		gtk20
LIB_DEPENDS=		curl:${PORTSDIR}/ftp/curl

USE_X_PREFIX=		yes
GNU_CONFIGURE=		yes

MAN1=			streamtuner.1 streamtuner-theme-convert.1

.include <bsd.port.mk>
