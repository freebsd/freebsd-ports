# Ports collection Makefile for:	PyKQueue
# Date created:				05/23/2000
# Whom:					dwhite@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		kqueue
PORTVERSION=		1.3
PORTREVISION=		1
CATEGORIES=		devel python
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dwhite
PKGNAMEPREFIX=		py-
DISTNAME=		PyKQueue-${PORTVERSION}

MAINTAINER=		dwhite@FreeBSD.org
COMMENT=	Python interface to kqueue(2) and kevent(2) system calls

USE_PYTHON=		yes
USE_REINPLACE=		yes
PLIST_SUB+=		PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S/^${LOCALBASE}\///g}

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
