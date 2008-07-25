# New ports collection makefile for:	py-distorm
# Date created:				1 December 2006
# Whom:					Lutz Boehne <lboehne@damogran.de>
#
# $FreeBSD$
#

PORTNAME=	distorm
PORTVERSION=	1.7.29
CATEGORIES=	devel python
MASTER_SITES=	http://www.ragestorm.net/distorm/ \
		http://www.damogran.de/ports/distorm/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}64-pkg${PORTVERSION}.tar.bz2 \
		diSlib64.py
EXTRACT_ONLY=	${PORTNAME}64-pkg${PORTVERSION}.tar.bz2

MAINTAINER=	bf2006a@yahoo.com
COMMENT=	Fast x86 and x86-64 disassembler library with Python interface

USE_BZIP2=	yes
USE_PYTHON=	yes

WRKSRC=		${WRKDIR}/distorm/build/linux
ALL_TARGET=	py
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/distorm.so \
		bin/diSlib64.py

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/py-distorm
PORTDOCS=	distorm.html qa.txt vol1.html vol2.html
.endif

post-patch:
	${REINPLACE_CMD} -e 's,python2.4,${PYTHON_VERSION},' ${WRKDIR}/distorm/src/pydistorm.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/distorm.so ${PYTHON_SITELIBDIR}
	${ECHO_CMD} '#!'${PYTHON_CMD} | ${CAT} - ${DISTDIR}/diSlib64.py \
	> ${WRKDIR}/diSlib64.py
	${INSTALL_SCRIPT} ${WRKDIR}/diSlib64.py ${PREFIX}/bin

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKDIR}/distorm/doc/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
