# New ports collection makefile for:	freehdl
# Date created:				19 Oct 2006
# Whom:					lon_kamikaze@gmx.de
#
# $FreeBSD$
#

PORTNAME=	freehdl
PORTVERSION=	0.0.3
CATEGORIES=	cad
MASTER_SITES=	http://cran.mit.edu/~enaroska/

MAINTAINER=	lon_kamikaze@gmx.de
COMMENT=	A free VHDL simulator

USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_PERL5=	yes
USE_XLIB=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--x-libraries=${X11BASE}/lib \
		--prefix=${PREFIX}

MAN1=		freehdl-config.1 \
		freehdl-gennodes.1 \
		freehdl-libtool.1 \
		freehdl-v2cc.1 \
		gvhdl.1
MAN5=		v2cc.libs.5

INFO=		fire

MANCOMPRESSED=	no

PLIST_TMP=	${WRKDIR}/plist_tmp/

PLIST_REPL=	${SED} "s|share/${PORTNAME}|%%DATADIR%%|1"

plist: build
	@${ECHO} "===>  Rebuilding PLIST."
	@${TOUCH} ${PLIST}
	@${RM} ${PLIST}
	@cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} \
		prefix=${PLIST_TMP} ${INSTALL_TARGET}
	@${RM} -rf ${PLIST_TMP}/man ${PLIST_TMP}/info
	@${FIND} -d ${PLIST_TMP} -not -type d \
		| ${SED} "s|${PLIST_TMP}||1" \
		| ${PLIST_REPL} >> ${PLIST}
	@${FIND} -d ${PLIST_TMP} -type d -mindepth 2 \
		| ${SED} "s|${PLIST_TMP}|@dirrm |1" \
		| ${PLIST_REPL} >> ${PLIST}
	@${RM} -rf ${PLIST_TMP}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	doesn't link
.endif

.include <bsd.port.post.mk>
