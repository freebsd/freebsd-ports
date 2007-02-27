# New ports collection makefile for:	Kochi CID-keyed fonts
# Date created:				Jan 24 2003
# Whom:				KOMATSU Shinichiro <koma2@jiro.c.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	kochi-cidfonts
PORTVERSION=	0.017
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.jp/efont/dist/Kochi-CID/${PORTVERSION}/
DISTNAME=	Kochi-CID-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Japanese CID-keyed fonts named 'Kochi'

USE_BZIP2=	yes
NO_BUILD=	yes

FONTSBASEDIR=	share/fonts
FONTSDIR=	${FONTSBASEDIR}/CIDFont
PLIST_SUB=	FONTSDIR=${FONTSDIR} FONTSBASEDIR=${FONTSBASEDIR}

do-install:
	${MKDIR} ${PREFIX}/${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/Kochi-* ${PREFIX}/${FONTSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README-CID.sjis ${DOCSDIR}
.endif

.include <bsd.port.mk>
