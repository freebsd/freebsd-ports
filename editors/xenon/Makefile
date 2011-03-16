# New ports collection makefile for:	Xenon
# Date created:				22 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	xenon
PORTVERSION=	1.0.0
PORTREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	http://sydney.proximity.com.au/~ben/xenon/dist/ \
		ftp://yankee.proximitygroup.com/pub/xenon/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple X-based text editor

DEPRECATED=	Upstream disapear and distfile is no more available
EXPIRATION_DATE=	2011-05-01

USE_GMAKE=	yes
USE_XORG=	xpm
MAKEFILE=	${WRKSRC}/makefiles/Makefile.Linux
NOPRECIOUSSOFTMAKEVARS=	yes
EXAMPLESDIR=	${PREFIX}/share/examples/ex

MAN1=		xe.1

FIX_FILES=	Xe.h XeApp.C XeApp.h XeFontTable.C XeKeyTable.C \
		XeKeyTable.h XeObject.C XeObject.h XeObjectTable.h XeText.C \
		XeText.h

do-configure:
.for file in ${FIX_FILES}
	@${REINPLACE_CMD} -e 's|#include <ext/|#include <|' \
		-e 's|ulong|u_long|g' -e 's|uint|u_int|g' \
		-e 's|#include <slist>|#include <list>|' \
		-e 's|std::slist|std::list|g' \
		-e 's|#include <hash_map>|#include <ext/hash_map>|' \
		-e 's|std::hash_map|__gnu_cxx::hash_map|g' \
		-e 's|std::hash|__gnu_cxx::hash|g' \
			${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} '/friend int compare/d' ${WRKSRC}/KrAtom.h
	@${REINPLACE_CMD} 's|<Undo\*>|<class Undo*>|' ${WRKSRC}/XeText.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xe ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xe.1 ${PREFIX}/man/man1
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/xerc ${EXAMPLESDIR}/sample.xerc
.endif

.include <bsd.port.mk>
