# New ports collection makefile for:	libnjb
# Date created:				16 July 2006
# Whom:					adrianm
#
# $FreeBSD$
#

PORTNAME=	libnjb
PORTVERSION=	2.2.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library, API for communicating with Creative and Dell audio players

LIB_DEPENDS=	usb:${PORTSDIR}/devel/libusb

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

.ifdef WITH_PORTDOCS
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
PLIST_SUB=	DOCS="" PORTVERSION=${PORTVERSION}
.else
PLIST_SUB=	DOCS="@comment "
NODOC=		/^SUBDIRS/s|doc||
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|;\
		${NODOC}' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
