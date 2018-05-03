# Created by: Alexey V. Antipovsky <kemm@in-line.ru>
# $FreeBSD$

PORTNAME=	libspectrum
PORTVERSION=	1.4.2
CATEGORIES=	emulators devel
MASTER_SITES=	SF/fuse-emulator/${PORTNAME}/${PORTVERSION}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Handling of ZX-Spectrum emulator files formats

LICENSE=	GPLv2

LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile \
		libgcrypt.so:security/libgcrypt

GNU_CONFIGURE=	yes
USES=		gettext gmake libtool pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS ChangeLog README THANKS \
	    doc/libspectrum.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
