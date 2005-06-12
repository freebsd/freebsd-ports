# New ports collection makefile for:	unmakeself
# Date created:			31 Mar 2005
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		unmakeself
PORTVERSION=		1.0
CATEGORIES=		archivers
DISTFILES=

MAINTAINER=		jylefort@FreeBSD.org
COMMENT=		Extract Makeself archives

LDFLAGS=		-larchive -lbz2 -lz
USE_GETOPT_LONG=	yes
NO_WRKSUBDIR=		yes

PLIST_FILES=		bin/unmakeself

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502103
BUILD_DEPENDS+=		${LOCALBASE}/lib/libarchive.a:${PORTSDIR}/archivers/libarchive
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
.endif

do-build:
	${CC} ${CFLAGS} ${CPPFLAGS} -o ${WRKSRC}/unmakeself \
		${FILESDIR}/unmakeself.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unmakeself ${PREFIX}/bin

.include <bsd.port.post.mk>
