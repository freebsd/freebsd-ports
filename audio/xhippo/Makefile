# New ports collection makefile for:	xhippo
# Version required:			1.05
# Date created:				16 March 1999
# Whom:					Rod Taylor <tr49986@rcc.on.ca>
#
# $Id: Makefile,v 1.2 1999/05/29 03:51:59 steve Exp $
#

DISTNAME=	xhippo-1.05
CATEGORIES=	audio
MASTER_SITES=	http://zenchaos.netpedia.net/software/

MAINTAINER=	tr49986@rcc.on.ca

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123
LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"
USE_XLIB=	yes

post-install:
	@if [ ! -f ${PREFIX}/etc/xhippo.config ]; then \
		${INSTALL_SCRIPT} ${WRKSRC}/xhippo.config \
		    ${PREFIX}/etc ; \
	fi
	${INSTALL_SCRIPT} ${WRKSRC}/xhippo.config \
		${PREFIX}/etc/xhippo.config.default
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
