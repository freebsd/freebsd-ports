# New ports collection makefile for:	gai-album
# Date created:		2005-02-10
# Whom:			David Thiel <lx@redundancy.redundancy.org>
#
# $FreeBSD$
#

PORTNAME=	gai-album
PORTVERSION=	0.7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gai

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	A GAI dockapp for viewing xmms visualizations

LIB_DEPENDS=	gai:${PORTSDIR}/x11-toolkits/gai \
		xmms:${PORTSDIR}/multimedia/xmms

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|\(GNOMEDIR=\).*|\1"${PREFIX}"|; \
		 s|share\(/pixmaps\)|share/gnome\1|; \
		 s|:GNOME_|:GAI-|g; \
		 s|\(@APPLET_NAME@\)\(Applet\)|\1-\2|g; \
		 s|\(Applet\)_\(Factory\)|\1-\2|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|lib\(/bonobo\)|libdata\1|; \
		 s|share\(/pixmaps\)|share/gnome\1|; \
		 s|-O3||' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
