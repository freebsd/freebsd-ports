# New ports collection makefile for:	libhoard
# Date created:			May 24, 2003
# Whom:				Sergey A. Osokin <osa@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libhoard
PORTVERSION=	2.1.2d
CATEGORIES=	devel
MASTER_SITES=	http://www.cs.umass.edu/~emery/software/

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Fast, scalable and memory-efficient allocator for MP

USE_GMAKE=	yes
MAKE_ENV=	USE_FREEBSD=1 \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
INSTALLS_SHLIB=	YES

.include <bsd.port.pre.mk>

TESTPROG=	testos

check-os:
.if !defined(SKIP_OS_TEST)
	-@${MKDIR} ${WRKSRC} ; \
	${RM} -f ${WRKSRC}/${TESTPROG} ; \
	${CC} ${PTHREAD_CFLAGS} ${PTHREAD_LIBS} -o ${WRKSRC}/${TESTPROG} \
		${PATCHDIR}/${TESTPROG}.c > /dev/null 2>&1 ;
	@if [ ! -f ${WRKSRC}/${TESTPROG} ] ; \
	then \
	${ECHO_MSG} "You must have a version of FreeBSD later than 4.8-STABLE" ; \
	${ECHO_MSG} "27 May 2003 or 5.1-RELEASE to compile and use libhoard" ; \
	exit 1 ; \
	fi
	@${WRKSRC}/${TESTPROG} 2>/dev/null
.endif

pre-fetch:	check-os

do-install:
	${INSTALL_DATA} ${WRKSRC}/libhoard.so ${PREFIX}/lib/libhoard.so.1
	${LN} -sf ${PREFIX}/lib/libhoard.so.1 ${PREFIX}/lib/libhoard.so
.if !defined(NOPORTDOCS)
	${INSTALL} -d -m 0755 ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/asplos2000.pdf ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
