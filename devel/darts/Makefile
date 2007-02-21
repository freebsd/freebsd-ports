# New ports collection makefile for:	darts
# Date created:		2 April 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	darts
PORTVERSION=	0.31
CATEGORIES=	devel
MASTER_SITES=	http://www.chasen.org/~taku/software/darts/src/

MAINTAINER=	laszlof@FreeBSD.org
COMMENT=	A C++ template library that implements Double-Array

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=   --build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

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
