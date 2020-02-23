# Created by: dwhite@FreeBSD.org
# $FreeBSD$

PORTNAME=		kqueue
PORTVERSION=		1.4
PORTREVISION=		2
CATEGORIES=		devel python
MASTER_SITES=		http://ox.eicat.ca/~dgilbert/files/
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		PyKQueue-${PORTVERSION}
EXTRACT_SUFX=		.tbz

MAINTAINER=		ports2@dclg.ca
COMMENT=		Python interface to kqueue(2) and kevent(2) system calls

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

USES=		python:2.7 tar:bzip2
FILES=		kqsyscallmodule.so KQueue.py KQueue.pyc
PLIST_FILES=	${FILES:S+^+%%PYTHON_SITELIBDIR%%/+g}
MAKE_ENV=	MAINCC=${CC}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,@DEFS@,,' \
		-e 's,^PYTHON=\(.*\)python,PYTHON=\1${PYTHON_CMD},' \
		${WRKSRC}/Makefile.pre.in

do-configure:
	@(cd ${WRKSRC} && \
	make -f Makefile.pre.in boot)
	${GREP} '^BLDSHARED' ${PYTHON_LIBDIR}/config/Makefile >> \
		${WRKSRC}/Makefile

post-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/kqsyscallmodule.so ${STAGEDIR}${PYTHON_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/KQueue.py ${STAGEDIR}${PYTHON_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/KQueue.pyc ${STAGEDIR}${PYTHON_SITELIBDIR}/

.include <bsd.port.post.mk>
