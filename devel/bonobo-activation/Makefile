# New ports collection makefile for:   bonobo-activation
# Date Created:			13 February 2002
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bonobo-activation
PORTVERSION=	0.9.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	pre-gnome2/releases/gnome-2.0-desktop-alpha2
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		ORBit-2.0:${PORTSDIR}/devel/ORBit2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_BISON=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -pthread"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

pre-patch:
	@find ${WRKSRC} -name Makefile.in | xargs ${PERL} -pi -e \
		's|\$\(libdir\)/pkgconfig|\$\(prefix\)/libdata/pkgconfig|g ; \
		 s|\$\(libdir\)/bonobo/servers|\$\(prefix\)/libdata/bonobo/servers|g'

.include <bsd.port.mk>
