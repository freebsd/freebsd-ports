# New ports collection makefile for:	pylint
# Date created:		28 May 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	jsl
PORTVERSION=	0.3.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.Awfulhak.org/pub/jsl/ \
		http://www.javascriptlint.com/download/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Analyzes javascript code looking for bugs and signs of poor quality

PLIST_FILES=	bin/jsl
ONLY_FOR_ARCHS=	i386
WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_GMAKE=	yes
MAKEFILE=	Makefile.ref

.include <bsd.port.pre.mk>

JSLCFG!=	${UNAME} -sr | ${SED} 's, ,,'

post-patch:
	${LN} -s Linux_All.mk ${WRKSRC}/config/${JSLCFG}.mk

do-install:
	${INSTALL} ${WRKSRC}/${JSLCFG}_DBG.OBJ/jsl ${PREFIX}/bin/jsl

.include <bsd.port.post.mk>
