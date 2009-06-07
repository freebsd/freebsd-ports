# New ports collection makefile for:	gai-album
# Date created:		2005-02-10
# Whom:			David Thiel <lx@redundancy.redundancy.org>
#
# $FreeBSD$
#

PORTNAME=	gai-album
PORTVERSION=	0.7
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gai

MAINTAINER=	lx@FreeBSD.org
COMMENT=	A GAI dockapp that works with xmms to display album covers

LIB_DEPENDS=	gai:${PORTSDIR}/x11-toolkits/gai \
		xmms:${PORTSDIR}/multimedia/xmms

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix

DEPRECATED=	abandoned project, does not build
EXPIRATION_DATE=	2009-07-07

post-patch:
	@${REINPLACE_CMD} -e \
		's|\(GNOMEDIR=\).*|\1"${PREFIX}"|; \
		 s|:GNOME_|:GAI-|g; \
		 s|\(@APPLET_NAME@\)\(Applet\)|\1-\2|g; \
		 s|\(Applet\)_\(Factory\)|\1-\2|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|lib\(/bonobo\)|libdata\1|; \
		 s|-O3||' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
