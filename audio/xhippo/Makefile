# New ports collection makefile for:	xhippo
# Date created:				16 March 1999
# Whom:					Rod Taylor <rod@zort.on.ca>
#
# $FreeBSD$
#

PORTNAME=	xhippo
PORTVERSION=	2.7
CATEGORIES=	audio
MASTER_SITES=	http://zenchaos.netpedia.net/software/ \
		http://www.us-lot.org/~azz/xhippo/

MAINTAINER=	rod@zort.on.ca

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123
LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

post-install:
	${INSTALL_DATA} ${WRKSRC}/xhippo.config ${PREFIX}/etc/xhippo.config.default
.if !exists(${PREFIX}/etc/xhippo.config)
	${CP} ${PREFIX}/etc/xhippo.config.default ${PREFIX}/etc/xhippo.config
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
