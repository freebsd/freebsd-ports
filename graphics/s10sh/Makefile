# New ports collection makefile for:	s10sh
# Date created:				Tue Feb 27 00:16:34 MST 2001
# Whom:					John Reynolds <jjreynold@home.com>
#
# $FreeBSD$
#

PORTNAME=	s10sh
PORTVERSION=	0.1.91
CATEGORIES=	graphics
MASTER_SITES=	http://www.kyuzz.org/antirez/s10sh-src/

PATCH_SITES=http://www.reynoldsnet.org/s10sh/ \
	    http://members.home.net/jjreynold/s10sh/
PATCHFILES=${PORTNAME}-${PORTVERSION}.patches.gz
PATCH_DIST_STRIP=-p1

MAINTAINER=	jjreynold@home.com

# Don't extract the libusb bundled with s10sh:
EXTRACT_AFTER_ARGS=     | ${TAR} -xf - --exclude '*/libusb*'

MAKEFILE=	${FILESDIR}/Makefile.bsd

.if defined(NOUSB) || defined(WITHOUT_USB)
MAKE_ENV+=	WITHOUT_USB=YES
.else
LIB_DEPENDS=    usb-0.1.3:${PORTSDIR}/devel/libusb
.endif

.if !defined(NOPORTDOCS)
DOCDIR=	share/doc/s10sh
PLIST_SUB+=	DOCDIR="${DOCDIR}"
post-install:
	${MKDIR} ${LOCALBASE}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${LOCALBASE}/${DOCDIR}
.endif

.include <bsd.port.mk>
