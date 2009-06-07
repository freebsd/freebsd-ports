# New ports collection makefile for:	gai-visual-audio
# Date created:		2005-02-10
# Whom:			David Thiel <lx@redundancy.redundancy.org>
#
# $FreeBSD$
#

PORTNAME=	gai-visual-audio
PORTVERSION=	0.3
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gai

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	A GAI dockapp for displaying xmms visualizations

LIB_DEPENDS=	gai:${PORTSDIR}/x11-toolkits/gai \
		xmms:${PORTSDIR}/multimedia/xmms

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix

DEPRECATED=	abandoned project, does not build
EXPIRATION_DATE=	2009-07-07

post-patch:
	@${REINPLACE_CMD} -e 's|\(GNOMEDIR=\).*|\1"${PREFIX}"|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|:GNOME_|:GAI-|g; \
		 s|\(@APPLET_NAME@\)\(Applet\)|\1-\2|g; \
		 s|\(Applet\)_\(Factory\)|\1-\2|' \
		${WRKSRC}/GNOME_DefaultApplet.server.in
	@${REINPLACE_CMD} -e \
		's|lib\(/bonobo\)|libdata\1|; \
		 s|-O3||' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-O3|${CFLAGS}|' ${WRKSRC}/plugin/Makefile

post-build:
	@cd ${WRKSRC}/plugin && ${MAKE_ENV} ${MAKE} ${MAKE_ARGS}

post-install:
	@cd ${WRKSRC}/plugin && ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} ${INSTALL_TARGET}

.include <bsd.port.mk>
