# New ports collection makefile for:	xhippo
# Version required:			2.1
# Date created:				16 March 1999
# Whom:					Rod Taylor <rod@zort.on.ca>
#
# $FreeBSD$
#

DISTNAME=	xhippo-2.1
CATEGORIES=	audio
MASTER_SITES=	http://zenchaos.netpedia.net/software/

MAINTAINER=	rod@zort.on.ca

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
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
