# New ports collection Makefile for:	seed7
# Date created:				16 July 2008
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	seed7
DISTVERSION=	05_20080707
CATEGORIES=	lang
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A high-level, extensible programming language

USE_GMAKE=	yes
USE_XORG=	x11

WRKSRC=	${WRKDIR}/${PORTNAME}/src
MAKEFILE=	makefile
ALL_TARGET=	hi

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    ${WRKSRC}/makefile

do-configure:
	(cd ${WRKSRC} && ${GMAKE} depend)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hi ${PREFIX}/bin
	${INSTALL} -d ${PREFIX}/lib/${PORTNAME}
	(cd ${WRKSRC}/../lib && ${COPYTREE_SHARE} \* ${PREFIX}/lib/${PORTNAME})

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}
	(cd ${WRKSRC}/../doc && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif
.if !defined(NOPORTEXAMPLES)
	${INSTALL} -d ${EXAMPLESDIR}
	(cd ${WRKSRC}/../prg && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
