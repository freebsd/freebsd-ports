# New ports collection makefile for:	laughingman
# Date created:				2007-07-13
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	laughingman
PORTVERSION=	0.20070610
PORTREVISION=	1
CATEGORIES=	games multimedia graphics
MASTER_SITES=	http://www.masayashi.com/wp-content/uploads/2007/04/
DISTNAME=	LaughingMan_proj
EXTRACT_SUFX=	.lzh
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	nork@FreeBSD.org
COMMENT=	A real-time face hijacking program made by the ultimate hacker Aoi

LIB_DEPENDS=	cv.1:${PORTSDIR}/graphics/opencv
EXTRACT_DEPENDS=lha:${PORTSDIR}/archivers/lha

EXTRACT_CMD=	lha
EXTRACT_BEFORE_ARGS=xiq2
EXTRACT_AFTER_ARGS=

NO_WRKSUBDIR=	yes

MAKE_ENV+=	BINDIR=${PREFIX}/bin \
		DATADIR=${DATADIR}

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
