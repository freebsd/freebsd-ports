# Created by: Alexey V. Antipovsky <kemm@in-line.ru>
# $FreeBSD$

PORTNAME=	libspectrum
PORTVERSION=	1.5.0
CATEGORIES=	emulators devel
MASTER_SITES=	SF/fuse-emulator/${PORTNAME}/${PORTVERSION}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Handling of ZX-Spectrum emulator files formats

LICENSE=	GPLv2

LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile \
		libgcrypt.so:security/libgcrypt

GNU_CONFIGURE=	yes
USES=		gettext gmake gnome libtool perl5 pkgconfig
USE_GNOME=	glib20
USE_PERL5=	build
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS ChangeLog README THANKS \
	    doc/libspectrum.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
