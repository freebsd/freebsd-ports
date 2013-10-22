# Created by: Olexandr Davydenko <o.davydenko@gmail.com>
# $FreeBSD$

PORTNAME=	libftdi
PORTVERSION=	0.20
CATEGORIES=	devel
MASTER_SITES=	http://www.intra2net.com/en/developer/libftdi/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library (using libusb) to talk to FTDI chips

OPTIONS_DEFINE+=	BOOST PYTHON
BOOST_DESC=		Build with boost
PYTHON_DESC=		Python bindings

USE_AUTOTOOLS=		autoconf libtool automake
GNU_CONFIGURE=		yes
CFLAGS+=		-I${LOCALBASE}/include
USE_LDCONFIG=		yes
USES=			pathfix pkgconfig

PORTDOCS=		COPYING.LIB ChangeLog README

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBOOST}
PLIST_SUB+=		BOOST=""
CONFIGURE_ARGS+=	--with-boost
CXXFLAGS+=		"-I${LOCALBASE}/include"
LIB_DEPENDS+=		libboost_system.so:${PORTSDIR}/devel/boost-libs
.else
PLIST_SUB+=		BOOST="@comment "
CONFIGURE_ARGS+=	--without-boost
.endif
.if ${PORT_OPTIONS:MPYTHON}
PLIST_SUB+=		PYTHON="" PYDISTUTILS_EGGINFO=${PYDISTUTILS_EGGINFO}
CONFIGURE_ARGS+=	--enable-python-binding
CONFIGURE_ENV+=		SWIG="${LOCALBASE}/bin/swig2.0"
BUILD_DEPENDS+=		swig2.0:${PORTSDIR}/devel/swig20
USE_PYTHON=		yes
.else
PLIST_SUB+=		PYTHON="@comment "
.endif

EXTRA_PATCHES=	${FILESDIR}/extra-patch-configure.in

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS

post-patch:
	@${REINPLACE_CMD} -E -e \
		's:\$$\(libdir\)/pkgconfig:${PREFIX}/libdata/pkgconfig:' \
		${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in

pre-configure:
	@cd ${WRKSRC} && ${AUTORECONF} --force --install

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
