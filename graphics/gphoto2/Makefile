# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	gphoto2
PORTVERSION=	2.5.5
CATEGORIES=	graphics
MASTER_SITES=	SF/gphoto/gphoto/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line frontend to libgphoto2

LICENSE=	GPLv2

LIB_DEPENDS=	libpopt.so:${PORTSDIR}/devel/popt \
		libgphoto2.so:${PORTSDIR}/graphics/libgphoto2

USES=		gmake pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	POPT_CFLAGS="$$(pkg-config --cflags popt)" \
		POPT_LIBS="$$(pkg-config --libs popt)" \
		ac_cv_lib_pthread_pthread_exit=no
CONFIGURE_ARGS=	--without-cdk

OPTIONS_DEFINE=		AALIB DOCS NLS READLINE
OPTIONS_DEFAULT=	AALIB READLINE
OPTIONS_SUB=		yes

AALIB_DESC=		Text mode capture preview support
AALIB_LIB_DEPENDS=	libaa.so:${PORTSDIR}/graphics/aalib
AALIB_CONFIGURE_WITH=	aalib
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_CPPFLAGS=		-I${LOCALBASE}/include
NLS_LIBS=		-L${LOCALBASE}/lib -lintl
READLINE_USES=		readline
READLINE_CONFIGURE_WITH=readline

post-install:
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
