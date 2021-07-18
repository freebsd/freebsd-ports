# Created by: Anders Nordby <anders@fix.no>

PORTNAME=	gphoto2
PORTVERSION=	2.5.26
CATEGORIES=	graphics
MASTER_SITES=	SF/gphoto/gphoto/${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Command-line frontend to libgphoto2

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexif.so:graphics/libexif \
		libgphoto2.so:graphics/libgphoto2 \
		libpopt.so:devel/popt

USES=		gmake jpeg pkgconfig tar:bzip2

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	POPT_CFLAGS="$$(pkg-config --cflags popt)" \
		POPT_LIBS="$$(pkg-config --libs popt)"
CONFIGURE_ARGS=	--without-cdk

OPTIONS_DEFINE=		AALIB DOCS NLS READLINE THREADS
OPTIONS_DEFAULT=	AALIB READLINE THREADS
OPTIONS_SUB=		yes

AALIB_DESC=		Text mode capture preview support
AALIB_LIB_DEPENDS=	libaa.so:graphics/aalib
AALIB_CONFIGURE_WITH=	aalib
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
READLINE_USES=		readline
READLINE_CONFIGURE_WITH=	readline
THREADS_CONFIGURE_ENV_OFF=	ac_cv_lib_pthread_pthread_exit=no

post-install-DOCS-on:
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
