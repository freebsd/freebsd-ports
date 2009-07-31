# New ports collection makefile for:	aolserver-nsgd
# Date created:		12 Oct 2006
# Whom:			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nsgd
PORTVERSION=	2.0
PORTREVISION=	6
CATEGORIES=	graphics www
MASTER_SITES=	http://www.aolserver.cz/download/
PKGNAMEPREFIX=	aolserver-
DISTNAME=	${PORTNAME}2
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	aolserver

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Graphics module for AOLserver

WRKSRC=		${WRKDIR}

AOLSERVERBASE?=	aolserver
LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd
BUILD_DEPENDS+=	${LOCALBASE}/${AOLSERVERBASE}/bin/nsd:${PORTSDIR}/www/aolserver
RUN_DEPENDS+=	${LOCALBASE}/${AOLSERVERBASE}/bin/nsd:${PORTSDIR}/www/aolserver

USE_GMAKE=	yes

USE_TCL=	84+
USE_TCL_THREADS=	yes

.include <bsd.port.pre.mk>

CFLAGS+=	"-I${LOCALBASE}/include"

MAKE_ARGS=	NSHOME="${LOCALBASE}/${AOLSERVERBASE}" \
		MODLIBS="-L${LOCALBASE}/lib -lgd" \
		DLLLIBS="-L${LOCALBASE}/lib -lgd"

PLIST_FILES=	${AOLSERVERBASE}/bin/nsgd2.so \
		${AOLSERVERBASE}/lib/libnsgd2.a \
		${AOLSERVERBASE}/lib/libnsgd2.so

PORTDOCS=	nsgd.html

post-patch:
	@${REINPLACE_CMD} -e 's/CFLAGS   =/CFLAGS  +=/g' \
		-e '/^OBJS     =.*/{p;s/OBJS     =.*/MODOBJS  = $$(OBJS)/g;}' \
		-e 's/^MODLIBS  =/#MODLIBS  =/g' \
		${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@ ${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
