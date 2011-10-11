# ex:ts=8
# Ports collection makefile for:	burrtools
# Date created:			Mar 23, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	burrtools
PORTVERSION=	0.6.2
CATEGORIES=	games
MASTER_SITES=	SF \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	A puzzle solver

LICENSE=	GPLv3

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		xmlwrapp.5:${PORTSDIR}/textproc/xmlwrapp \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk \
		boost_thread:${PORTSDIR}/devel/boost-libs

USE_XORG=	x11 xt xext xmu xi
USE_GL=		glu
USE_GMAKE=	yes
USE_GCC=	4.2+
GNU_CONFIGURE=	yes
CPPFLAGS+=	`fltk-config --cxxflags`
LDFLAGS+=	`fltk-config --ldflags`
MAKE_JOBS_SAFE=	yes

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/burrTxt bin/burrTxt2 bin/burrGui

.include <bsd.port.pre.mk>

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

.include <bsd.port.post.mk>
