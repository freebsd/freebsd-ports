# ex:ts=8
# Ports collection makefile for:  stlport
# Date Created:			  2 December 1998
# Whom:				  Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

PORTNAME=	stlport
PORTVERSION=	4.5.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.stlport.com/archive/
PKGNAMESUFFIX=	-${COMPILER}
DISTNAME=	STLport-${PORTVERSION:S/.b/-b/}

MAINTAINER=	pmarquis@pobox.com

.include <bsd.port.pre.mk>

.if !exists(/usr/include/wchar.h)
BROKEN=		"Requires /usr/include/wchar.h for compilation"
.endif

WRKSRC=		${WRKDIR}/STLport-${PORTVERSION:S/.b/b/}/src
PATCH_WRKSRC=	${WRKDIR}/STLport-${PORTVERSION:S/.b/b/}
USE_GMAKE=	yes
COMPILER?=	gcc
MAKEFILE=	${COMPILER}-freebsd.mak
MAKE_ARGS+=	INSTALLDIR=${PREFIX} PTHREAD_CFLAGS=${PTHREAD_CFLAGS} \
		PTHREAD_LIBS=${PTHREAD_LIBS}
PLIST_SUB=	COMPILER=${COMPILER}

INSTALL_TARGET=	install_unix
INSTALLS_SHLIB=	yes

.if ${OSVERSION} < 440000
BROKEN=		"Not supported on systems prior to FreeBSD 4.4"
.endif

.if ${COMPILER} == icc
CC=	icc
CXX=	icpc
.endif

.if ${COMPILER} == gcc && ${OSVERSION} < 460000
pre-everything:
	@${ECHO_MSG}
	@${ECHO_MSG} "There may be a bug in your version of gcc's exception"
	@${ECHO_MSG} "handling code.  Consider upgrading to FreeBSD 4.6"
	@${ECHO_MSG} "or above."
.endif

post-patch:
	@${CP} ${FILESDIR}/src::icc-freebsd.mak ${WRKSRC}/icc-freebsd.mak
	@${CP} ${FILESDIR}/stlport::stl_icc.h \
		${WRKSRC}/../stlport/config/stl_icc.h
	@${CP} ${FILESDIR}/test::eh::icc-freebsd.mak \
		${WRKSRC}/../test/eh/icc-freebsd.mak

post-install:
	${FIND} ${PREFIX}/include/stlport -name \*.orig -delete
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/../doc/*.css ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/images/* ${DOCSDIR}/images
.endif

.if ${OSVERSION} >= 46000 || ${COMPILER} == icc
post-build:	test
.endif

test:
	cd ${WRKSRC}/../test/eh && ${SETENV} CC=${CC} CXX=${CXX} \
	${GMAKE} -f ${MAKEFILE} PTHREAD_CFLAGS=${PTHREAD_CFLAGS} \
	PTHREAD_LIBS=${PTHREAD_LIBS} PTHREAD_CFLAGS=${PTHREAD_CFLAGS} \
	PTHREAD_LIBS=${PTHREAD_LIBS} CC=${CC} CXX=${CXX}

.include <bsd.port.post.mk>
