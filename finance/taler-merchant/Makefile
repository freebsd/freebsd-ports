PORTNAME=	taler-merchant
DISTVERSION=	1.5.9
CATEGORIES=	finance
MASTER_SITES=	http://ftpmirror.gnu.org/taler/

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Privacy-preserving distributed payment system (merchant components)
WWW=		https://www.taler.net/en/index.html

LICENSE=	GPLv3
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnunetpq.so:net/gnunet \
		libtalerutil.so:finance/taler-exchange \
		libjansson.so:devel/jansson \
		libltdl.so:devel/libltdl \
		libcurl.so:ftp/curl \
		libqrencode.so:graphics/libqrencode \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libmicrohttpd.so:www/libmicrohttpd

EXTRACT_SUFX=	.tar.gz
USES=		compiler:c11 cpe gettext-runtime libtool pgsql pkgconfig \
		shebangfix tar

CPE_VENDOR=	gnu

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBRARY_PATH=${PREFIX}/lib
CONFIGURE_ARGS=	--with-gnunet=${PREFIX} \
		--with-microhttpd=${PREFIX}

CFLAGS+=	-I${PREFIX}
LDFLAGS+=	-L${PREFIX} -pthread

SHEBANG_FILES=	contrib/taler-merchant-dbconfig \
		src/backend/taler-merchant-report-generator-email \
		src/backend/taler-merchant-report-generator-file

.include <bsd.port.mk>
