# New ports collection makefile for:	gview
# Date created:				30 April 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	gview
PORTVERSION=	0.1.14
CATEGORIES=	graphics
MASTER_SITES=	http://netpedia.net/hosting/gview/ \
		http://homepages.petech.ac.za/~bruces/ \
		ftp://ftp.petech.ac.za/pub/viewers/

MAINTAINER=	cpiazza@FreeBSD.org

LIB_DEPENDS=	gdk_imlib.5:${PORTSDIR}/graphics/imlib

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		GTK_CONFIG="${GTK_CONFIG}"

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gview
.for file in AUTHORS BUGS ChangeLog NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gview
.endfor
.endif

.include <bsd.port.mk>
