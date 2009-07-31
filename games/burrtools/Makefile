# ex:ts=8
# Ports collection makefile for:	burrtools
# Date created:			Mar 23, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	burrtools
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A puzzle solver

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		xmlwrapp.5:${PORTSDIR}/textproc/xmlwrapp \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk

USE_XORG=	x11 xt xext xmu xi
USE_GL=		glu
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/burrTxt bin/burrTxt2 bin/burrGui

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/burrTxt ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/burrTxt2 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/gui/burrGui ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in burricons.ico AUTHORS ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples; ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
