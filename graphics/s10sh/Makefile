# New ports collection makefile for:	s10sh
# Date created:				Tue Feb 27 00:16:34 MST 2001
# Whom:					John Reynolds <johnjen@reynoldsnet.org>
#
# $FreeBSD$
#

PORTNAME=	s10sh
PORTVERSION=	0.2.0
PORTREVISION=   1
CATEGORIES=	graphics
MASTER_SITES=	http://www.kyuzz.org/antirez/s10sh-src/

MAINTAINER=	johnjen@reynoldsnet.org

# Don't extract the libusb bundled with s10sh:
EXTRACT_AFTER_ARGS=     | ${TAR} -xf - --exclude '*/libusb*'

MAKEFILE=	${FILESDIR}/Makefile.bsd

.if defined(NOUSB) || defined(WITHOUT_USB)
MAKE_ENV+=	WITHOUT_USB=YES
.else
LIB_DEPENDS=	usb-0.1.4:${PORTSDIR}/devel/libusb
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
