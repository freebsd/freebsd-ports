# New ports collection makefile for:	imhangul_status_applet
# Date created:				26 May 2003
# Whom:					CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	imhangul_status_applet
PORTVERSION=	0.2
CATEGORIES=	korean gnome
MASTER_SITES=	http://download.kldp.net/imhangul/

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	GNOME2 status applet of imhangul

BROKEN=		Broken dependency

RUN_DEPENDS=	${LOCALBASE}/lib/lib/gtk-2.0/immodules/im-hangul.so:${PORTSDIR}/korean/imhangul

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomepanel
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
