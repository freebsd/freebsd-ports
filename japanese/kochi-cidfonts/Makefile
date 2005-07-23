# New ports collection makefile for:	Kochi CID-keyed fonts
# Date created:				Jan 24 2003
# Whom:				KOMATSU Shinichiro <koma2@jiro.c.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	kochi-cidfonts
PORTVERSION=	0.017
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.jp/efont/dist/Kochi-CID/${PORTVERSION}/
DISTNAME=	Kochi-CID-${PORTVERSION}

MAINTAINER=	kanou@khdd.net
COMMENT=	Free Japanese CID-keyed fonts named 'Kochi'

BROKEN=		Incomplete pkg-plist
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

USE_BZIP2=	yes
NO_BUILD=	yes

FONTSDIR=	share/fonts/CIDFont
PLIST_SUB=	FONTSDIR=${FONTSDIR}

do-install:
	${MKDIR} ${PREFIX}/${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/Kochi-* ${PREFIX}/${FONTSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README-CID.sjis ${DOCSDIR}
.endif

.include <bsd.port.mk>
