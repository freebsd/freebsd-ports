# New ports collection makefile for:	dc3play
# Date created:		15 Jul 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

PORTNAME=	dc3play
PORTVERSION=	19991202
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.itojun.org/pub/digi-cam/DC-3/unix/ \
		ftp://ftp.digipri.co.jp/pub/free-software/Ricoh/DC-3/unix/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Digital camera downloading tool for Ricoh DC-3

RESTRICTED=	"Beta test period, redistribution prohibited"

WRKSRC=		${WRKDIR}/${PORTNAME}/build

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OPTFLAG=""

PORTDOCS=	PROTOCOL README.english README.japanese
PLIST_FILES=	bin/dc3play

post-patch:
	@${REINPLACE_CMD} -e "s|<sys/dir.h>|<dirent.h>|g" ${WRKSRC}/../src/*.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in PROTOCOL README.english README.japanese
	${INSTALL_DATA} ${WRKSRC}/../${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
