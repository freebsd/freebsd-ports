# Ports collection makefile for:	spidermonkey
# Date created:	Fri Apr 18, 2003
# Whom:	Dan Rench (citric@cubicone.tmetic.com)
#
# $FreeBSD$

PORTNAME=	js
PORTVERSION=	1.5.p6
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	js
DISTNAME=	js-1.5-rc6

MAINTAINER=	citric@cubicone.tmetic.com
COMMENT=	A standalone JavaScript interpreter from the Mozilla project

CONFLICTS=	njs-*

USE_GMAKE=	YES
INSTALLS_SHLIB=	YES

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
BROKEN=		"Does not compile on amd64 or ia64 (missing -fPIC)"
.endif

JS_ARCH:=	`uname -s``uname -r`
JS_HEADERS!=	${GREP} '\.h$$' ${MASTERDIR}/pkg-plist | ${SED} 'sX^include/XX'

post-extract:
	${MV} ${WRKDIR}/js/src ${WRKSRC} && \
	${RM} -rf js && \
	${CP} ${WRKSRC}/config/Linux_All.mk \
		${WRKSRC}/config/${JS_ARCH}.mk && \
	${CP} ${WRKSRC}/Makefile.ref ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${JS_ARCH}_DBG.OBJ/js \
		${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${JS_ARCH}_DBG.OBJ/libjs.so \
		${PREFIX}/lib
	${CP} ${WRKSRC}/${JS_ARCH}_DBG.OBJ/jsautocfg.h ${WRKSRC}
.for jsh in ${JS_HEADERS}
	@${INSTALL_DATA} ${WRKSRC}/${jsh} ${PREFIX}/include/
.endfor

.include <bsd.port.post.mk>
