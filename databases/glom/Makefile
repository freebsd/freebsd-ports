# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/databases/glom/Makefile,v 1.30 2010/11/04 15:57:03 kwm Exp $

PORTNAME=	glom
PORTVERSION=	1.12.2
PORTREVISION=	10
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GNOME database designer and user interface

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgdamm-4.0.so:${PORTSDIR}/databases/libgdamm \
		libgconfmm-2.6.so:${PORTSDIR}/devel/gconfmm26 \
		libgtksourceviewmm-2.0.so:${PORTSDIR}/x11-toolkits/libgtksourceviewmm \
		libavahi-ui.so:${PORTSDIR}/net/avahi-gtk \
		libepc-1.0.so:${PORTSDIR}/www/libepc \
		libgoocanvasmm-1.0.so:${PORTSDIR}/graphics/goocanvasmm
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/libgda-postgres-4.0.pc:${PORTSDIR}/databases/libgda4-postgresql
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/libgda-postgres-4.0.pc:${PORTSDIR}/databases/libgda4-postgresql

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		desktop-file-utils gettext gmake libtool pathfix \
		pgsql pkgconfig shared-mime-info tar:bzip2
USE_GNOME=	gnomedocutils gnomeprefix pygnomeextras
USE_LDCONFIG=	yes
USE_PYTHON=	yes
INSTALLS_OMF=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-postgres-utils=${LOCALBASE}/bin
INSTALLS_ICONS=	yes

# Note: USE_PGSQL has already been set above.
BUILD_DEPENDS+=	postmaster:${PORTSDIR}/databases/postgresql${PGSQL_VER_NODOT}-server
RUN_DEPENDS+=	postmaster:${PORTSDIR}/databases/postgresql${PGSQL_VER_NODOT}-server

.include <bsd.port.mk>
