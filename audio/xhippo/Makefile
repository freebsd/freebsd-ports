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

USE_XLIB=	yes
USE_GTK=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME)
USE_GNOME=	yes
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/xhippo.config ${PREFIX}/etc/xhippo.config.default
.if !exists(${PREFIX}/etc/xhippo.config)
	${CP} ${PREFIX}/etc/xhippo.config.default ${PREFIX}/etc/xhippo.config
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
