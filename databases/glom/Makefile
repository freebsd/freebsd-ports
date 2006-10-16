# New ports collection makefile for:	glom
# Date created:				24 April, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/databases/glom/Makefile,v 1.9 2006/09/05 03:44:45 mezz Exp $
#

PORTNAME=	glom
PORTVERSION=	1.0.4
CATEGORIES=	databases gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME database designer and user interface

LIB_DEPENDS=	bakery-2.4:${PORTSDIR}/x11-toolkits/bakery \
		gdamm-1.3:${PORTSDIR}/databases/libgdamm \
		gnomecanvasmm-2.6:${PORTSDIR}/graphics/libgnomecanvasmm26
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes

USE_BZIP2=	yes
USE_XLIB=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomedocutils gnomehack gnomeprefix pygnomeextras
USE_LDCONFIG=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

INSTALLS_ICONS=	yes

.include <bsd.port.pre.mk>

.if (${OSVERSION} < 500000)
BROKEN=		doesn't play well with 4.X.
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-update-mime-database|true|g' ${WRKSRC}/Makefile.in

post-install:
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.post.mk>
