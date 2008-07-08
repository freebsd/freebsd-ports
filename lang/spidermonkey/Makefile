# Ports collection makefile for:	spidermonkey
# Date created:		Fri Apr 18, 2003
# Whom:			Dan Rench <citric@cubicone.tmetic.com>
#
# $FreeBSD$

PORTNAME=	spidermonkey
DISTVERSION=	1.7.0
CATEGORIES=	lang
MASTER_SITES=	http://ftp.mozilla.org/pub/mozilla.org/js/ \
		http://ftp.belnet.be/mirrors/ftp.mozilla.org/js/ \
		http://gentoo.netnitco.net/distfiles/ \
		http://gd.tuwien.ac.at/opsys/linux/gentoo/distfiles/ \
		ftp://ftp.mozilla.org/pub/mozilla.org/js/
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
MAKE_ENV+=	CC="${CC}" CCC="${CXX}"
USE_LDCONFIG=	yes
SRC_DIR=	js/src
JSH=		jsapi.h jsautocfg.h jsconfig.h jscompat.h jslong.h jsosdep.h \
		jsotypes.h jspubtd.h jstypes.h jsstr.h jshash.h jsprvtd.h \
		jsproto.tbl
PLIST_FILES=	bin/js lib/libjs.so lib/libjs.so.1 ${JSH:S,^,include/,}
WRKSRC=		${WRKDIR}/${SRC_DIR}
EXTRACT_AFTER_ARGS=| ${TAR} -xf - \
		--exclude js/jsd

do-configure:
	${CP} ${WRKSRC}/config/Linux_All.mk \
		${WRKSRC}/config/${OPSYS}`${UNAME} -r`.mk && \

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${OPSYS}`${UNAME} -r`_DBG.OBJ/js \
		${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${OPSYS}`${UNAME} -r`_DBG.OBJ/libjs.so \
		${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libjs.so ${PREFIX}/lib/libjs.so.1
	${CP} ${WRKSRC}/${OPSYS}`${UNAME} -r`_DBG.OBJ/jsautocfg.h ${WRKSRC}
	@${INSTALL_DATA} ${JSH:S,^,${WRKSRC}/,} ${PREFIX}/include/

.include <bsd.port.mk>
