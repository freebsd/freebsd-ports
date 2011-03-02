# New ports collection makefile for:	usbmuxd
# Date created:				10 June 2010
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	usbmuxd
PORTVERSION=	1.0.6
CATEGORIES=	comms
MASTER_SITES=	http://marcansoft.com/uploads/${PORTNAME}/

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	A daemon for multiplexing connections over USB to an iPhone/iPod Touch

LIB_DEPENDS=	plist.1:${PORTSDIR}/devel/libplist

USE_BZIP2=	yes
MAKE_JOBS_SAFE=	yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS README README.devel

.include <bsd.port.pre.mk>

.if ${OSVERSION} == 800107 || ${OSVERSION} == 900002
HAVE_LIBUSB104!=	${GREP} --quiet "libusb_fill_bulk_transfer" \
				/usr/include/libusb.h \
				&& ${ECHO} yes || ${ECHO} no
.elif ${OSVERSION} > 800107 && ${OSVERSION} < 900000 || ${OSVERSION} > 900002
HAVE_LIBUSB104=		yes
.else
HAVE_LIBUSB104=		no
.endif
.if ${HAVE_LIBUSB104} == "no"
BROKEN=		requires libusb 1.0.4
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|$${LIB_SUFFIX}/pkgconfig|data/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

post-install:
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
