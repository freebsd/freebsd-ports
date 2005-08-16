# Ports collection makefile for:	spidermonkey
# Date created:	Fri Apr 18, 2003
# Whom:	Dan Rench (citric@cubicone.tmetic.com)
#
# $FreeBSD$

PORTNAME=	spidermonkey
DISTVERSION=	1.5-rc6a
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	js
DISTNAME=	js-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	citric@cubicone.tmetic.com
COMMENT=	A standalone JavaScript interpreter from the Mozilla project

CONFLICTS=	njs-*

.if !defined(WITHOUT_TEST)
USE_PERL5_BUILD=test harness
PATCHFILES=	spidermonkey-patch-tests-ecma.bz2	\
		spidermonkey-patch-tests-timezone.bz2	\
		spidermonkey-patch-tests-js.bz2
PATCH_SITES=	http://virtual-estates.net/~mi/port-stuff/
BUILD_DEPENDS+=	${SITE_PERL}/Getopt/Mixed.pm:${PORTSDIR}/devel/p5-Getopt-Mixed
DISTFILES+=	js-tests-20021118${EXTRACT_SUFX}
post-build:	test
post-patch:
	#
	# Removing known bad tests:
	#	https://bugzilla.mozilla.org/show_bug.cgi?id=10278
	#	https://bugzilla.mozilla.org/show_bug.cgi?id=101964
	#
	cd ${WRKDIR}/tests && ${RM} js1_3/regress/function-001-n.js	\
		js1_2/function/function-001-n.js	\
		js1_3/Script/function-001-n.js	\
		js1_5/Array/regress-101964.js

.endif

USE_GMAKE=	YES
MAKEFILE=	Makefile.ref
ALL_TARGET=	${OPSYS}`${UNAME} -r`_DBG.OBJ/js
MAKE_ENV+=	CC="${CC}" CCC="${CXX}"
INSTALLS_SHLIB=	YES
SRC_DIR=	js/src
WRKSRC=	${WRKDIR}/${SRC_DIR}
EXTRACT_AFTER_ARGS=| ${TAR} -xf - \
		--exclude js/jsd	\
		--exclude ${SRC_DIR}/editline	\
		--exclude ${SRC_DIR}/fdlibm	\
		--exclude ${SRC_DIR}/liveconnect	\
		--exclude ${SRC_DIR}/perlconnect

test:
	cd ${WRKDIR}/tests && ${SETENV}	\
	    LD_LIBRARY_PATH=${WRKSRC}/${OPSYS}`${UNAME} -r`_DBG.OBJ	\
		${PERL5} jsDriver.pl	\
		    --shellpath ${WRKSRC}/${OPSYS}`${UNAME} -r`_DBG.OBJ/js \
		    --engine smdebug --confail --trace --list ecma* js1_*

.include <bsd.port.pre.mk>

do-configure:
	${CP} ${WRKSRC}/config/Linux_All.mk \
		${WRKSRC}/config/${OPSYS}`${UNAME} -r`.mk && \

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${OPSYS}`${UNAME} -r`_DBG.OBJ/js \
		${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${OPSYS}`${UNAME} -r`_DBG.OBJ/libjs.so \
		${PREFIX}/lib
	${CP} ${WRKSRC}/${OPSYS}`${UNAME} -r`_DBG.OBJ/jsautocfg.h ${WRKSRC}
.for jsh in jsapi.h jsautocfg.h jscompat.h jslong.h jsosdep.h jsotypes.h jspubtd.h jstypes.h
	@${INSTALL_DATA} ${WRKSRC}/${jsh} ${PREFIX}/include/
.endfor

.include <bsd.port.post.mk>
