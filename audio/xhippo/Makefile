# New ports collection makefile for:	xhippo
# Date created:				16 March 1999
# Whom:					Rod Taylor <rod@zort.on.ca>
#
# $FreeBSD$
#

PORTNAME=	xhippo
PORTVERSION=	3.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	xhippo

MAINTAINER=	kevlo@FreeBSD.org

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

USE_XLIB=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS=	CFLAGS="${CFLAGS}"

DOCS=		ChangeLog gnu-xhippo.html screenshot.jpeg xhippo.html.gz \
		xhippo.info.gz xhippo.ps.gz xhippo.sgml xhippo.txt.gz

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomelibs}!=""
USE_GNOME+=	gnomelibs
PKGNAMESUFFIX=	-gnome
CONFIGURE_ARGS+=	--with-gnome
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xhippo
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${PREFIX}/share/doc/xhippo
.endfor
.endif
	${INSTALL_DATA} ${WRKSRC}/xhippo.config ${PREFIX}/etc/xhippo.config.default
.if !exists(${PREFIX}/etc/xhippo.config)
	${CP} ${PREFIX}/etc/xhippo.config.default ${PREFIX}/etc/xhippo.config
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
