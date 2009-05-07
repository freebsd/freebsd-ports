# New ports collection makefile for:	freehdl
# Date created:				19 Oct 2006
# Whom:					lon_kamikaze@gmx.de
#
# $FreeBSD$
#

PORTNAME=	freehdl
PORTVERSION=	0.0.7
CATEGORIES=	cad
MASTER_SITES=	http://freehdl.seul.org/~enaroska/

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	A free VHDL simulator

USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_PERL5=	yes
USE_GNOME=	gnomehack \
		pkgconfig
USE_AUTOTOOLS=	libtool:15
HAS_CONFIGURE=	yes

MAN1=		freehdl-config.1 \
		freehdl-gennodes.1 \
		freehdl-v2cc.1 \
		gvhdl.1
MAN5=		v2cc.libs.5

INFO=		fire

MANCOMPRESSED=	no
MAKE_JOBS_SAFE=	yes

PLIST_TMP=	${WRKDIR}/plist_tmp/

PLIST_REPL=	${SED} "s|share/${PORTNAME}|%%DATADIR%%|1"

plist: build
	@${ECHO} "===>  Rebuilding PLIST."
	@${TOUCH} ${PLIST}
	@${RM} ${PLIST}
	@cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} \
		prefix=${PLIST_TMP} \
		mandir=${PLIST_TMP}/man \
		infodir=${PLIST_TMP}/info \
		${INSTALL_TARGET}
	@${RM} -rf ${PLIST_TMP}/man ${PLIST_TMP}/info
	@${FIND} -d ${PLIST_TMP} -not -type d \
		| ${SED} "s|${PLIST_TMP}||1" \
		| ${PLIST_REPL} >> ${PLIST}
	@${FIND} -d ${PLIST_TMP} -type d -mindepth 2 \
		| ${SED} "s|${PLIST_TMP}|@dirrm |1" \
		| ${PLIST_REPL} \
		| ${GREP} -E '%%DATADIR%%|freehdl' >> ${PLIST}
	@${FIND} -d ${PLIST_TMP} -type d -mindepth 2 \
		| ${SED} "s|${PLIST_TMP}|@dirrmtry |1" \
		| ${PLIST_REPL} \
		| ${GREP} -vE '%%DATADIR%%|freehdl' >> ${PLIST}
	@${RM} -rf ${PLIST_TMP}

.include <bsd.port.mk>
