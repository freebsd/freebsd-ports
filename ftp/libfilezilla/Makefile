PORTNAME=	libfilezilla
PORTVERSION=	0.47.0
CATEGORIES=	ftp
MASTER_SITES=	https://download.filezilla-project.org/${PORTNAME}/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	C++ library for building platform-independent programs
WWW=		https://lib.filezilla-project.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp \
		libgnutls.so:security/gnutls \
		libnettle.so:security/nettle

USES=		compiler:c++17-lang gettext gmake iconv:wchar_t libtool \
		localbase pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
