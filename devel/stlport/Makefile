# ex:ts=8
# Ports collection makefile for:  stlport
# Date Created:			  2 December 1998
# Whom:				  Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

PORTNAME=	stlport
PORTVERSION=	4.6.2
PORTREVISION?=	0
CATEGORIES=	devel
MASTER_SITES=	http://www.stlport.com/archive/
PKGNAMESUFFIX=	-${COMPILER}
DISTNAME=	STLport-${PORTVERSION:S/.b/-b/}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	Adaptation of SGI's Standard Template Library

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" 
BROKEN=		"Segfault during build on alpha"
.endif

.if !exists(/usr/include/wchar.h)
BROKEN=		"Requires /usr/include/wchar.h for compilation"
.endif

WRKSRC=		${WRKDIR}/STLport-${PORTVERSION:S/.b/b/}/src
PATCH_WRKSRC=	${WRKDIR}/STLport-${PORTVERSION:S/.b/b/}
USE_GMAKE=	yes
COMPILER?=	gcc
MAKEFILE=	${COMPILER}-freebsd.mak
MAKE_ENV+=	CC=${CC} CXX=${CXX}
MAKE_ARGS+=	INSTALLDIR=${PREFIX} PTHREAD_CFLAGS=${PTHREAD_CFLAGS} \
		PTHREAD_LIBS=${PTHREAD_LIBS}
PLIST_SUB+=	COMPILER=${COMPILER}

INSTALL_TARGET=	install_unix
INSTALLS_SHLIB=	yes

.if ${OSVERSION} < 440000
BROKEN=		"Not supported on systems prior to FreeBSD 4.4"
.endif

.if ${COMPILER} == icc
CC=		icc
CXX=		icpc
CFLAGS=		-O -ip -axiMKW
CXXFLAGS=	${CFLAGS}
.else
# There's segfault on -current if you use non default CFLAGS.
CFLAGS=		-O -pipe
CXXFLAGS=	${CFLAGS}
.endif

.if ${COMPILER} == gcc && ${OSVERSION} < 460000
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "There may be a bug in your version of gcc's exception"
	@${ECHO_MSG} "handling code.  Consider upgrading to FreeBSD 4.6"
	@${ECHO_MSG} "or above."
.elif ${COMPILER} == gcc && ${OSVERSION} >= 502126
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "If you have encounted a compiler internal error"
	@${ECHO_MSG} "during building, do NOT 'make clean', simply continue"
	@${ECHO_MSG} "building by type 'make ${.TARGET}' again."
	@${ECHO_MSG}
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

test:	do-build
	@cd ${WRKSRC}/../test/eh && ${SETENV} ${MAKE_ENV} \
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check_d

.include <bsd.port.post.mk>
