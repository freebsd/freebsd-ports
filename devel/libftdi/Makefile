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
USE_GNOME=		pkgconfig gnomehack

PORTDOCS=		COPYING.LIB ChangeLog README

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBOOST}
PLIST_SUB+=		BOOST=""
CONFIGURE_ARGS+=	--with-boost
CXXFLAGS+=		"-I${LOCALBASE}/include"
LIB_DEPENDS+=		boost_system:${PORTSDIR}/devel/boost-libs
.else
PLIST_SUB+=		BOOST="@comment "
CONFIGURE_ARGS+=	--without-boost
.endif
.if ${PORT_OPTIONS:MPYTHON}
PLIST_SUB+=		PYTHON=""
CONFIGURE_ARGS+=	--enable-python-binding
USE_PYTHON=		yes
.else
PLIST_SUB+=		PYTHON="@comment "
.endif

EXTRA_PATCHES=	${FILESDIR}/extra-patch-configure.in

post-patch:
	@${REINPLACE_CMD} -E -e \
		's:\$$\(libdir\)/pkgconfig:${PREFIX}/libdata/pkgconfig:' \
		${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in

pre-configure:
	@cd ${WRKSRC} && ${AUTORECONF} --force --install

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
