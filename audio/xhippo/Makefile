# New ports collection makefile for:	xhippo
# Date created:				16 March 1999
# Whom:					Rod Taylor <rod@zort.on.ca>
#
# $FreeBSD$
#

PORTNAME=	xhippo
PORTVERSION=	3.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	xhippo

MAINTAINER=	rod@zort.on.ca

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

USE_XLIB=	yes
USE_GTK=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS=	CFLAGS="${CFLAGS}"

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
