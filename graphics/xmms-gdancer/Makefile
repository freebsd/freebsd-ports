# New ports collection makefile for:	xmms-gdancer
# Date created:			2. Jul 2001
# Whom:				Alexander@Leidinger.net
#
# $FreeBSD$
#

PORTNAME=	xmms-gdancer
PORTVERSION=	0.4.6
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.figz.com/gdancer/files/
DISTNAME=	gdancer-$(PORTVERSION)

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	XMMS Visualization plugin, displays dancing figures

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

PLIST_FILES=	lib/xmms/Visualization/gdancer.so
USE_X_PREFIX=	yes
USE_GNOME=	gtk12 gdkpixbuf
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-pixbuf

post-install:
	-${RM} ${PREFIX}/lib/xmms/Visualization/gdancer.la
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
