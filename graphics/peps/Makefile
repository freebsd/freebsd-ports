# New ports collection makefile for:	peps
# Date created:				5 July 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	peps
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	petef

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts EPS images to anti-aliased PGM bitmaps

PLIST_FILES=	bin/peps

USE_GHOSTSCRIPT_RUN=	yes

RUN_DEPENDS=	pnmtopng:${PORTSDIR}/graphics/netpbm

pre-fetch:
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO} ""
	@${ECHO} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO} ""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's!cc -O3!${CC} ${CFLAGS}!' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/peps ${PREFIX}/bin

.include <bsd.port.mk>
