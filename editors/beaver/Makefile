# New ports collection makefile for:	beaver
# Date created:			11 Apr 2003
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		beaver
PORTVERSION=		0.3.1
PORTREVISION=		6
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		jylefort@brutele.be
COMMENT=		A programmer's text editor for GTK+ 2.0

BROKEN=			"Incomplete pkg-plist (does not use gettext correctly)"

USE_X_PREFIX=		yes
USE_GMAKE=		yes
USE_LIBTOOL_VER=	13
USE_REINPLACE=		yes
USE_GNOME=		gnomehack gnomeprefix gtk20 gtksourceview lthack

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|-D.*_DISABLE_DEPRECATED||g'

.include <bsd.port.mk>
