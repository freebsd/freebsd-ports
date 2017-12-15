# Created by: rene
# $FreeBSD$

PORTNAME=	fuse-utils
DISTVERSION=	1.4.0
CATEGORIES=	emulators
MASTER_SITES=	SF/fuse-emulator/${PORTNAME}/${PORTVERSION}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Utilities from the Free Unix Spectrum Emulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile \
		libgcrypt.so:security/libgcrypt \
		libpng.so:graphics/png \
		libspectrum.so:emulators/libspectrum

USES=		gettext iconv jpeg pkgconfig
USE_GNOME=	glib20

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libspectrum-prefix=${LOCALBASE} \
		--with-local-prefix=${LOCALBASE}

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS ChangeLog README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
