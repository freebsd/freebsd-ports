# New ports collection makefile for:	gtksee
# Date created:		Sun Nov 22 12:08:18 CET 1998
# Whom:			Dirk Froemberg <ibex@physik.TU-Berlin.DE>
#
# $FreeBSD$
#

PORTNAME=	gtksee
PORTVERSION=	0.5.6
CATEGORIES=	graphics
MASTER_SITES=	http://download.berlios.de/gtksee/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image viewer

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff
RUN_DEPENDS=	bzip:${PORTSDIR}/archivers/bzip
.if !exists(/usr/bin/bzip2)
RUN_DEPENDS+=	bzip2:${PORTSDIR}/archivers/bzip2
.endif

USE_GNOME=	gtk12 gnometarget
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

MAN1=		gtksee.1

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CFLAGS=""|CFLAGS="$$CFLAGS"|g' ${WRKSRC}/configure

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/gtksee.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
