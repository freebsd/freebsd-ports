# New ports collection makefile for:   adplay
# Date created:		10 August 2004
# Whom:			Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	adplay
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	adplug

MAINTAINER=	ehaupt@critical.ch
COMMENT=	AdLib player using adplug library

LIB_DEPENDS=	adplug-1.5.1:${PORTSDIR}/audio/libadplug

PLIST_FILES=	bin/adplay

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${CPPFLAGS}" \
		CXXFLAGS="${CXXFLAGS} ${CPPFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

MAN1=		adplay.1

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} > 500000
	${RM} ${WRKSRC}/src/getopt.h
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/adplay ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/adplay.1 ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
