# New ports collection makefile for:	py-distorm
# Date created:				1 December 2006
# Whom:					Lutz Boehne <lboehne@damogran.de>
#
# $FreeBSD$
#

PORTNAME=	distorm
PORTVERSION=	1.7.30
CATEGORIES=	devel python
MASTER_SITES=	http://www.ragestorm.net/distorm/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}64-pkg${PORTVERSION}.tar.bz2 \
		diSlib64.py
EXTRACT_ONLY=	${PORTNAME}64-pkg${PORTVERSION}.tar.bz2

MAINTAINER=	bf1783@gmail.com
COMMENT=	Fast x86 and x86-64 disassembler library with Python interface

USE_BZIP2=	yes
USE_PYTHON=	yes

WRKSRC=		${WRKDIR}/distorm64/build/linux
ALL_TARGET=	py
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/distorm.so \
		%%PYTHON_SITELIBDIR%%/pydistorm.py \
		bin/diSlib64.py

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
PORTDOCS=	distorm.html qa.txt vol1.html vol2.html README
.endif

post-patch:
	${REINPLACE_CMD} -e "s,python2.5,${PYTHON_VERSION}," \
	${WRKDIR}/distorm64/src/pydistorm.h
	${REINPLACE_CMD} -e "s,libdistorm64.so,${PYTHON_SITELIBDIR}/distorm.so," \
	${WRKDIR}/distorm64/python/pydistorm.py

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/distorm.so ${PYTHON_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/distorm64/python/pydistorm.py ${PYTHON_SITELIBDIR}
	${ECHO_CMD} '#!'${PYTHON_CMD} | ${CAT} - ${DISTDIR}/diSlib64.py \
	> ${WRKDIR}/diSlib64.py
	${INSTALL_SCRIPT} ${WRKDIR}/diSlib64.py ${PREFIX}/bin

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS:NREADME}
	${INSTALL_DATA} ${WRKDIR}/distorm64/doc/${f} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKDIR}/distorm64/python/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
