# New ports collection makefile for:	libftdi
# Date created:				2006-07-27
# Whom:					Olexandr Davydenko <o.davydenko@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libftdi
PORTVERSION=	0.18
CATEGORIES=	devel
MASTER_SITES=	http://www.intra2net.com/en/developer/libftdi/download/

MAINTAINER=	o.davydenko@gmail.com
COMMENT=	A library (using libusb) to talk to FTDI chips

OPTIONS=	BOOST	"Build with boost"	off

USE_AUTOTOOLS=		autoconf libtool automake
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CFLAGS="${CFLAGS} -I${LOCALBASE}/include"
USE_LDCONFIG=		yes
USE_GNOME=		pkgconfig gnomehack

PORTDOCS=		COPYING.LIB ChangeLog README

.include <bsd.port.pre.mk>

.if defined(WITH_BOOST)
PLIST_SUB+=		BOOST=""
CONFIGURE_ARGS+=	--with-boost
CXXFLAGS+=		"-I${LOCALBASE}/include"
LIB_DEPENDS+=		boost_system.4:${PORTSDIR}/devel/boost-libs
.else
PLIST_SUB+=		BOOST="@comment "
CONFIGURE_ARGS+=	--without-boost
.endif

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1:${PORTSDIR}/devel/libusb
.else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-configure.in
.endif

post-patch:
	@${REINPLACE_CMD} -E -e \
		's:\$$\(libdir\)/pkgconfig:${PREFIX}/libdata/pkgconfig:' \
		${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in

pre-configure:
	@cd ${WRKSRC} && ${AUTORECONF}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
