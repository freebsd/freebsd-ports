# New ports collection makefile for:   glib13
# Date Created:			28 July 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glib
PORTVERSION=	1.3.12
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gimp.org/pub/%SUBDIR%/ \
		ftp://ftp.cs.umn.edu/pub/gimp/%SUBDIR%/ \
		http://www.ameth.org/gimp/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/gimp/%SUBDIR%,}
MASTER_SITE_SUBDIR=	gtk/v${PORTVERSION:R}

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	giconv.2:${PORTSDIR}/converters/libiconv
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

NO_LATEST_LINK=	"Unstable, development version."

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

MAN1=		glib-genmarshal.1 glib-mkenums.1

pre-patch:
	@find ${WRKSRC} -type f | xargs ${GREP} -l iconv.h | \
		xargs ${PERL} -pi -e "s|iconv\.h|giconv.h|g"
	@find ${WRKSRC} -name Makefile.in | xargs ${PERL} -pi -e \
		's|\$\(libdir\)/pkgconfig|\$\(prefix\)/libdata/pkgconfig|g'

post-install:
	${INSTALL_DATA} ${WRKSRC}/glibconfig.h ${PREFIX}/include/glib-2.0

.include <bsd.port.mk>
