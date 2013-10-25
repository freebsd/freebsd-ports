# Created by: Dan Rench <citric@cubicone.tmetic.com>
# $FreeBSD$

PORTNAME=	spidermonkey17
DISTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	js
DISTNAME=	js-${DISTVERSION}

MAINTAINER=	citric@cubicone.tmetic.com
COMMENT=	A standalone JavaScript interpreter from the Mozilla project

LIB_DEPENDS=	nspr4.1:${PORTSDIR}/devel/nspr

CONFLICTS=	njs-[0-9]*

MAKE_ARGS+=	JS_THREADSAFE=YES \
		PROG_LIBS="-lreadline -ltermcap -lm ${PTHREAD_LIBS}" \
		LDFLAGS="-L${LOCALBASE}/lib"
CFLAGS+=	-I${LOCALBASE}/include/nspr

USE_GMAKE=	YES
MAKEFILE=	Makefile.ref
ALL_TARGET=	${OPSYS}`${UNAME} -r`_DBG.OBJ/js
MAKE_ENV+=	CCC="${CXX}"
USE_LDCONFIG=	yes
SRC_DIR=	js/src

JSH=		jsapi.h jsarena.h jsarray.h jsatom.h jsautocfg.h jsbool.h \
		jsclist.h jscntxt.h jscompat.h jsconfig.h jsdate.h jsdhash.h \
		jsdtoa.h jsemit.h jsexn.h jsfun.h jsgc.h jshash.h jsinterp.h \
		jsiter.h jslibmath.h jslock.h jslong.h jsmath.h jsnum.h jsobj.h \
		jsopcode.h jsosdep.h jsotypes.h jsparse.h jsprf.h jsprvtd.h \
		jspubtd.h jsutil.h jsregexp.h jsscan.h jsscope.h jsscript.h \
		jsstr.h jstypes.h jsxdrapi.h jsxml.h \
		js.msg jsproto.tbl

PLIST_FILES=	bin/js lib/libjs.so lib/libjs.so.1 ${JSH:S,^,include/,}
WRKSRC=		${WRKDIR}/${SRC_DIR}
EXTRACT_AFTER_ARGS=	--exclude js/jsd

OPTIONS_DEFINE=	UTF8

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUTF8}
CFLAGS+=	-DJS_C_STRINGS_ARE_UTF8
.endif

do-configure:
	${CP} ${WRKSRC}/config/Linux_All.mk \
		${WRKSRC}/config/${OPSYS}`${UNAME} -r`.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${OPSYS}`${UNAME} -r`_DBG.OBJ/js \
		${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${OPSYS}`${UNAME} -r`_DBG.OBJ/libjs.so \
		${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libjs.so ${PREFIX}/lib/libjs.so.1
	${CP} ${WRKSRC}/${OPSYS}`${UNAME} -r`_DBG.OBJ/jsautocfg.h ${WRKSRC}
	@${INSTALL_DATA} ${JSH:S,^,${WRKSRC}/,} ${PREFIX}/include/

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64" && ${OSVERSION} > 900000
BROKEN=		Does not build on sparc64-9: fails to link
.endif

.include <bsd.port.post.mk>
