# New ports collection makefile for:	qiv
# Date created:		25 December 1998
# Whom:			Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	qiv
PORTVERSION=	2.1.p12
CATEGORIES=	graphics
MASTER_SITES=	http://www.klografx.net/qiv/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.p12/-pre12/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	carpetsmoker@xs4all.nl
COMMENT=	Small, fast GDK/Imlib image viewer

OPTIONS=	XINERAMA "use multiple monitors" off
USE_GETOPT_LONG=yes
USE_GMAKE=	yes
USE_GNOME=	imlib

MAN1=		qiv.1
PLIST_FILES=	bin/qiv

.include <bsd.port.pre.mk>

pre-configure:
.if ! defined(WITH_XINERAMA)
.else
	@${REINPLACE_CMD} 's|GTD.*=|#|' ${WRKSRC}/Makefile
.endif

do-configure:
	@${REINPLACE_CMD} 's|/usr/bin|${PREFIX}/bin|g' \
		${WRKSRC}/qiv.1
	@${REINPLACE_CMD} 's|/usr/local|${PREFIX}|; \
		s|gcc|${CC}|; \
		s|-O2|${CFLAGS}|; \
		s|libs-gdk`|libs-gdk` ${LDFLAGS}|;' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qiv ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/qiv.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.post.mk>
