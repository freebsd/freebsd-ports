# Ports collection makefile for:	spidermonkey
# Date created:	Fri Apr 18, 2003
# Whom:	Dan Rench (citric@cubicone.tmetic.com)
#
# $FreeBSD$

PORTNAME=	spidermonkey
DISTVERSION=	1.5-rc6a
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	js
DISTNAME=	js-${DISTVERSION}

MAINTAINER=	citric@cubicone.tmetic.com
COMMENT=	A standalone JavaScript interpreter from the Mozilla project

CONFLICTS=	njs-*

USE_GMAKE=	YES
INSTALLS_SHLIB=	YES

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
BROKEN=		"Does not compile on amd64 or ia64 (missing -fPIC)"
.endif

post-extract:
	${MV} ${WRKDIR}/js/src ${WRKSRC} && \
	${RM} -rf js && \
	${CP} ${WRKSRC}/config/Linux_All.mk \
		${WRKSRC}/config/`uname -s``uname -r`.mk && \
	${CP} ${WRKSRC}/Makefile.ref ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/`uname -s``uname -r`_DBG.OBJ/js \
		${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/`uname -s``uname -r`_DBG.OBJ/libjs.so \
		${PREFIX}/lib
	${CP} ${WRKSRC}/`uname -s``uname -r`_DBG.OBJ/jsautocfg.h ${WRKSRC}
.for jsh in jsapi.h jsautocfg.h jscompat.h jslong.h jsosdep.h jsotypes.h jspubtd.h jstypes.h
	@${INSTALL_DATA} ${WRKSRC}/${jsh} ${PREFIX}/include/
.endfor

.include <bsd.port.post.mk>
