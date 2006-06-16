# New ports collection makefile for:	libgpod
# Date created:				Wed Jan 1 00:48:58 EST 2006
# Whom:					Devon Ryan <dpryan@dpryan.com>
#
# $FreeBSD$
#

PORTNAME=	libgpod
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtkpod

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A library for direct access of iPod's contents

USE_GNOME=	gtk20
USE_GETTEXT=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

post-extract: .SILENT
	${REINPLACE_CMD} -e \
		's,libdir)/pkgconfig,prefix)/libdata/pkgconfig,' \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} '19323,19345d' ${WRKSRC}/configure
	${REINPLACE_CMD} -e '25s,^,#include <sys/types.h>,' \
		${WRKSRC}/src/db-parse-context.c
.if defined(GCCVERSION)
.   if ${GCCVERSION} < 030000
	${REINPLACE_CMD} -e 's,\[\],[0],' ${WRKSRC}/src/db-itunes-parser.h
.   endif
.else
.   if ${OSVERSION} < 500035
	${REINPLACE_CMD} -e 's,\[\],[0],' ${WRKSRC}/src/db-itunes-parser.h
.   endif
.endif

.include <bsd.port.post.mk>
