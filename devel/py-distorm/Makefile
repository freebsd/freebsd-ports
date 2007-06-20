# New ports collection makefile for:	py-distorm
# Date created:				1 December 2006
# Whom:					Lutz Boehne <lboehne@damogran.de>
#
# $FreeBSD$
#

PORTNAME=	distorm
PORTVERSION=	1.7.23
CATEGORIES=	devel python
MASTER_SITES=	http://www.ragestorm.net/distorm/ \
		http://www.damogran.de/ports/distorm/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-pkg${PORTVERSION}

MAINTAINER=	lboehne@damogran.de
COMMENT=	Fast x86 and x86-64 disassembler library for python

USE_BZIP2=	yes
USE_PYTHON=	yes

WRKSRC=		${WRKDIR}/distorm/build/linux

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/py-distorm
DOCS=		distorm.html qa.txt vol1.html vol2.html
.endif

post-patch:
	${REINPLACE_CMD} -e s,XXPYTHON_LIBDIRXX,${PYTHON_LIBDIR}, ${WRKDIR}/distorm/build/linux/Makefile
	${REINPLACE_CMD} -e s,python2.4,${PYTHON_VERSION}, ${WRKDIR}/distorm/src/pydistorm.h

.if !defined(NOPORTDOCS)
pre-install:
	${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKDIR}/distorm/doc/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
