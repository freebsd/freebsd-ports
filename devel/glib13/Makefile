# New ports collection makefile for:   glib13
# Date Created:			28 July 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glib
PORTVERSION=	1.3.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gimp.org/pub/%SUBDIR%/ \
		ftp://ftp.cs.umn.edu/pub/gimp/%SUBDIR%/ \
		http://www.ameth.org/gimp/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/gimp/%SUBDIR%,}
MASTER_SITE_SUBDIR=	gtk/v${PORTVERSION:R}

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	giconv.2:${PORTSDIR}/converters/libiconv
#iconv.1:${PORTSDIR}/converters/iconv

NO_LATEST_LINK=	"Unstable, development version."

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		glib-config-2.0.1 glib-genmarshal.1

pre-patch:
	@find ${WRKSRC} -type f | xargs ${GREP} -l iconv.h | \
		xargs ${PERL} -pi -e "s|iconv\.h|giconv.h|g"

.include <bsd.port.mk>
