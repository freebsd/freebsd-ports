# New ports collection makefile for:   atk
# Date Created:			14 May 2001
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	atk
PORTVERSION=	0.9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	pre-gnome2/sources/atk
#MASTER_SITES=	ftp://ftp.gimp.org/pub/%SUBDIR%/ \
#		ftp://ftp.cs.umn.edu/pub/gimp/%SUBDIR%/ \
#		http://www.ameth.org/gimp/%SUBDIR%/ \
#		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/gimp/%SUBDIR%,}
#MASTER_SITE_SUBDIR=	gtk/v1.3

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	pango.0:${PORTSDIR}/x11-toolkits/pango \
		glib-1.3.12:${PORTSDIR}/devel/glib13
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

pre-patch:
	@find ${WRKSRC} -name Makefile.in | xargs ${PERL} -pi -e \
		's|\$\(libdir\)/pkgconfig|\$\(prefix\)/libdata/pkgconfig|g'

.include <bsd.port.mk>
