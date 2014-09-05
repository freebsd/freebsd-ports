# Created by: lon_kamikaze@gmx.de
# $FreeBSD$

PORTNAME=	freehdl
PORTVERSION=	0.0.7
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://freehdl.seul.org/~enaroska/

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	Free VHDL simulator

USE_LDCONFIG=	yes
USES=		gmake pathfix libtool:build makeinfo perl5 pkgconfig
USE_GCC=	any
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

INFO=		fire

PLIST_TMP=	${WRKDIR}/plist_tmp/

PLIST_REPL=	${SED} "s|share/${PORTNAME}|%%DATADIR%%|1"

plist: build
	@${ECHO} "===>  Rebuilding PLIST."
	@${TOUCH} ${PLIST}
	@${RM} ${PLIST}
	@cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
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
