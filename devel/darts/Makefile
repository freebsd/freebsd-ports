# New ports collection makefile for:	darts
# Date created:		2 April 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	darts
PORTVERSION=	0.2
CATEGORIES=	devel
MASTER_SITES=	http://cl.aist-nara.ac.jp/~taku-ku/software/darts/src/

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A C++ template library that implements Double-Array

GNU_CONFIGURE=	yes

EXAMPLES=	darts.cpp mkdarts.cpp
DOCS=		AUTHORS ChangeLog README doc

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
.for f in ${EXAMPLES}
	${CP} -R ${WRKSRC}/${f} ${EXAMPLESDIR}/
.endfor
	${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
