PORTNAME=	gitte
DISTVERSION=	0.8.1
CATEGORIES=	deskutils gnome
MASTER_SITES=	https://codeberg.org/ckruse/Gitte/archive/${DISTVERSION}${EXTRACT_SUFX}?dummy=/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Simple Git client for GNOME
WWW=		https://codeberg.org/ckruse/Gitte #gitte

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene

USES=		cargo desktop-file-utils gettext gnome meson pkgconfig
USE_GNOME=	cairo gtk40 libadwaita pango

GLIB_SCHEMAS=	de.wwwtech.gitte.gschema.xml

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
MAKE_ENV=	${CARGO_ENV}

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	TEST
TEST_DESC=	Run appstream and desktop-file validation tests
TEST_BUILD_DEPENDS=	appstreamcli:devel/appstream \
			desktop-file-validate:devel/desktop-file-utils

post-patch:
	@${REINPLACE_CMD} -e '/update_desktop_database/d' \
		${WRKSRC}/meson.build

.include "${.CURDIR}/Makefile.crates"
.include <bsd.port.mk>
