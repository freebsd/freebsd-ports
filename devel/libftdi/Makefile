# New ports collection makefile for:	libftdi
# Date created:				2006-07-27
# Whom:					Olexandr Davydenko <o.davydenko@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libftdi
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.intra2net.com/de/produkte/opensource/ftdi/TGZ/

MAINTAINER=	o.davydenko@gmail.com
COMMENT=	A library (using libusb) to talk to FTDI chips

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CFLAGS="${CFLAGS} -I${LOCALBASE}/include"
USE_LDCONFIG=		yes
USE_GNOME=		pkgconfig gnomehack

PORTDOCS=		COPYING.LIB ChangeLog README

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1:${PORTSDIR}/devel/libusb
.else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-configure.in
USE_AUTOTOOLS+=	autoconf:262
.endif

post-patch:
.if ${OSVERSION} >= 800069
	${RM} -f ${WRKSRC}/configure
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
