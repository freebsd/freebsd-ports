# New ports collection makefile for:	camediaplay
# Date created:		2 May 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

PORTNAME=	camediaplay
PORTVERSION=	20010211
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.itojun.org/pub/digi-cam/C-400L/unix/ \
		ftp://ftp.digipri.co.jp/pub/free-software/Olympus/C-400L/unix/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Digital camera downloading tool for Epson/Sanyo/Olympus/Agfa camera

WRKSRC=		${WRKDIR}/${PORTNAME}/build

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OPTFLAG=""
MAN1=		camediaplay.1

post-patch:
	@${REINPLACE_CMD} -e "s|<sys/dir.h>|<dirent.h>|g" ${WRKSRC}/../src/*.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/camediaplay
.for file in PROTOCOL README.english README.japanese
	${INSTALL_DATA} ${WRKSRC}/../${file} ${PREFIX}/share/doc/camediaplay
.endfor
.endif

.include <bsd.port.mk>
