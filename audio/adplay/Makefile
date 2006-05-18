# New ports collection makefile for:	adplay
# Date created:				10 August 2004
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	adplay
PORTVERSION=	1.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	adplug

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	AdLib player using adplug library

LIB_DEPENDS=	adplug-2.0.0:${PORTSDIR}/audio/libadplug

PLIST_FILES=	bin/adplay

GNU_CONFIGURE=	yes
USE_GCC=	3.4+

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libbinio
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
.else
	${CP} ${FILESDIR}/getopt.h ${WRKSRC}/src/
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/adplay ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/adplay.1 ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
