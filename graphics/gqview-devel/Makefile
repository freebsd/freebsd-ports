# New ports collection makefile for:	gqview-devel
# Date Created:				5 March 2003
# Whom:					Andrew Dolgov <cthulhu@cthulhu.ru>
# based on graphics/gqview port
#
# $FreeBSD$
#

PORTNAME=	gqview
PORTVERSION=	1.3.5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-devel

MAINTAINER=	cthulhu@cthulhu.ru
COMMENT=	Another gtk2-based graphic file viewer

USE_X_PREFIX=	yes
USE_GNOME=	gtk20
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.if !defined(WANT_GNOME) || defined(WITHOUT_GNOME)
CONFIGURE_ARGS=	--disable-gnome
.endif

MAN1=		gqview.1

post-patch:
	@${REINPLACE_CMD} -e 's|INCLUDED_LIBINTL=yes|INCLUDED_LIBINTL=no|g' \
		${WRKSRC}/aclocal.m4

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gqview
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gqview
.endif

.include <bsd.port.mk>
