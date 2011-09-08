# New ports collection makefile for:	usbmuxd
# Date created:				10 June 2010
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	usbmuxd
PORTVERSION=	1.0.7
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://marcansoft.com/uploads/${PORTNAME}/

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	A daemon for multiplexing connections over USB to an iPhone/iPod Touch

LIB_DEPENDS=	plist.1:${PORTSDIR}/devel/libplist

USE_PYTHON=	yes
PYTHON_NO_DEPENDS=	yes
USE_BZIP2=	yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS README README.devel

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 800107 || ${OSVERSION} >= 900000 && ${OSVERSION} <= 900002
BROKEN=		requires libusb 1.0.3
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|$${LIB_SUFFIX}/pkgconfig|data/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

post-install:
	${MKDIR} ${PYTHON_SITELIBDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/python-client/*.py \
		${PYTHON_SITELIBDIR}/${PORTNAME}/
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
