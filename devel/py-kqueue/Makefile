# Ports collection Makefile for:	PyKQueue
# Date created:				05/23/2000
# Whom:					dwhite@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		kqueue
PORTVERSION=		1.4
PORTREVISION=		1
CATEGORIES=		devel python
MASTER_SITES=		http://ox.eicat.ca/~dgilbert/files/
PKGNAMEPREFIX=		py-
DISTNAME=		PyKQueue-${PORTVERSION}
EXTRACT_SUFX=		.tbz

MAINTAINER=		ports@dclg.ca
COMMENT=	Python interface to kqueue(2) and kevent(2) system calls

USE_BZIP2=		yes
USE_PYTHON=		yes
FILES=			kqsyscallmodule.so KQueue.py KQueue.pyc
PLIST_FILES=		${FILES:S+^+%%PYTHON_SITELIBDIR%%/+g}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400018
IGNORE="requires new kqueue API"
.endif
.if ${OSVERSION} >= 500000 && ${OSVERSION} < 500010
IGNORE="requires new kqueue API"
.endif

post-patch:
.if ${PYTHON_REL} >= 230
	@${REINPLACE_CMD} -e 's,@DEFS@,,' ${WRKSRC}/Makefile.pre.in
.endif

do-configure:
	@(cd ${WRKSRC} && \
	make -f Makefile.pre.in boot)

post-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	${MKDIR} ${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/kqsyscallmodule.so ${PYTHON_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/KQueue.py ${PYTHON_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/KQueue.pyc ${PYTHON_SITELIBDIR}/

.include <bsd.port.post.mk>
