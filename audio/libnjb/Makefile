# New ports collection makefile for:	libnjb
# Date created:				16 July 2006
# Whom:					adrianm
#
# $FreeBSD$
#

PORTNAME=	libnjb
PORTVERSION=	2.2.6
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library, API for communicating with Creative and Dell audio players

LIB_DEPENDS=	usb-0.1.8:${PORTSDIR}/devel/libusb

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
PLIST_SUB=	PORTVERSION=${PORTVERSION}
.else
NODOC=		/^SUBDIRS/s|doc||
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|;\
		${NODOC}' ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
