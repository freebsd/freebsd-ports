# New ports collection makefile for:	beaver
# Date created:			11 Apr 2003
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		beaver
PORTVERSION=		0.3.0
CATEGORIES=		editors
MASTER_SITES=		http://savannah.nongnu.org/download/beaver/

MAINTAINER=		jylefort@brutele.be
COMMENT=		A programmer's text editor for GTK+ 2.0

BUILD_WRKSRC=		${WRKSRC}/src
USE_GNOME=		gtk20
INSTALL_WRKSRC=		${WRKSRC}/src

USE_X_PREFIX=		yes
USE_GMAKE=		yes

MANCOMPRESSED=		yes
MAN1=			beaver.1x

MAKE_ENV=		PREFIX="${PREFIX}" \
			MKDIR="${MKDIR}" \
			INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
			INSTALL_DATA="${INSTALL_DATA}" \
			INSTALL_MAN="${INSTALL_MAN}"

.include <bsd.port.mk>
