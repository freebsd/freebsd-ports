# New ports collection makefile for:	Ming
# Date created:		14 October 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ming
PORTVERSION=	0.0.9b
CATEGORIES=	graphics
MASTER_SITES=	http://www.opaque.net/ming/
EXTRACT_SUFX=	.tgz

MAINTAINER=	knu@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAKE_ARGS=	NOPROFILE=true

DOCS=		CHANGES \
		CREDITS \
		README \
		TODO

post-extract:
	${MKDIR} ${WRKSRC}/c++
	${CP} ${WRKSRC}/../c++_ext/ming.h ${WRKSRC}/c++/

post-patch:
	${PERL} -i -p \
		-e 's:"\.\./\.\./c\+\+_ext/ming\.h":<c++/ming.h>:g;' \
		-e 's:"\.\./\.\./ming\.h":<ming.h>:g;' \
		${WRKSRC}/../examples/c/* \
		${WRKSRC}/../examples/c++/* \
		${WRKSRC}/../examples/common/* \
		${WRKSRC}/c++/ming.h

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ming
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/../${f} ${PREFIX}/share/doc/ming/
.endfor
	${MKDIR} ${PREFIX}/share/examples/ming/common
	${INSTALL_DATA} ${WRKSRC}/../examples/common/* \
		 ${PREFIX}/share/examples/ming/common/
	${MKDIR} ${PREFIX}/share/examples/ming/c
	${INSTALL_DATA} ${WRKSRC}/../examples/c/*.c \
		 ${PREFIX}/share/examples/ming/c/
	${MKDIR} ${PREFIX}/share/examples/ming/c++
	${INSTALL_DATA} ${WRKSRC}/../examples/c++/*.cpp \
		 ${PREFIX}/share/examples/ming/c++/
.endif

.include <bsd.port.mk>
