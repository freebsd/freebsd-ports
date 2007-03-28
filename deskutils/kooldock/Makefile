# New ports collection makefile for:   kooldock
# Date created:        8 February 2007
# Whom:                Gustavo Perez
#
# $FreeBSD$
#

PORTNAME=		kooldock
PORTVERSION=		0.4.6
CATEGORIES=		deskutils
MASTER_SITES=		http://www.kde-apps.org/CONTENT/content-files/ \
			http://www.kde-look.org/CONTENT/content-files/ \
			http://freebsd.unixfreunde.de/sources/
DISTNAME=		${KDELOOKITEM}-${PORTNAME}

MAINTAINER=		gustau.perez@gmail.com
COMMENT=		OS-X dock-like for KDE

KDELOOKITEM=		50910

WRKSRC=			${WRKDIR}/kooldock

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool:15 automake:19:env autoconf:259:env
INSTALLS_ICONS=		yes
USE_GETTEXT=		yes
USE_KDELIBS_VER=	3

pre-configure:
	cd ${WRKSRC} && ${MAKE} -f Makefile.dist

MANCOMPRESSED=		yes

.include <bsd.port.mk>
