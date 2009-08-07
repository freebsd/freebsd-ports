# New ports collection makefile for:	libgpod
# Date created:				Wed Jan 1 00:48:58 EST 2006
# Whom:					Devon Ryan <dpryan@dpryan.com>
#
# $FreeBSD$
#

PORTNAME=	libgpod
PORTVERSION=	0.7.2
CATEGORIES=	audio
MASTER_SITES=	SF/gtkpod

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A library for direct access of iPod's contents

USE_GNOME=	gtk20
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
# Disable python bindings for now, something does not work there
CONFIGURE_ARGS=	--without-python

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--with-html-dir="${PREFIX}/share/doc"
.endif

pre-patch: .SILENT
# Adjust pkgconfigdir to the FreeBSD world
	${REINPLACE_CMD} -e \
		's,libdir)/pkgconfig,prefix)/libdata/pkgconfig,' \
		${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's, docs,,' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
