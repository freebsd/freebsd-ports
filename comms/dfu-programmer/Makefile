# New ports collection makefile for:   dfu-programmer
# Date created:        16 July 2009
# Whom:                elbarto@ArcadeBSD.org
#
# $FreeBSD$
#

PORTNAME=	dfu-programmer
PORTVERSION=	0.5.1
CATEGORIES=	comms
MASTER_SITES=	SF

MAINTAINER=	elbarto@ArcadeBSD.org
COMMENT=	Device Firmware Update based USB programmer for Atmel chips

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/dfu-programmer

MAN1=		dfu-programmer.1
PORTDOCS=	*

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
