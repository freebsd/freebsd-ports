# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-file-archiver
PORTVERSION=	1.6.0
CATEGORIES=	archivers mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Archive manager for zip files, tar, etc

RUN_DEPENDS=	${LOCALBASE}/bin/gtar:${PORTSDIR}/archivers/gtar \
    		${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_MATE=	autogen caja common:build docutils intlhack
USE_XORG=	sm
USE_GNOME=	glib20 gnomehier gtk20
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
CONFIGURE_ARGS=	--disable-packagekit \
		--with-gtk=2.0
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PATHFIX_MAKEFILEIN=	Makefile.*

GLIB_SCHEMAS=	org.mate.engrampa.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/fr-command-tar.c \
		${WRKSRC}/src/fr-command-zip.c

.include <bsd.port.mk>
