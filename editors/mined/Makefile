# New ports collection makefile for:	mined
# Date created:		24 December 2004
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	mined
PORTVERSION=	2000.12
CATEGORIES=	editors
MASTER_SITES=	http://towo.net/mined/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Text mode editor with Unicode support

MAKEFILE=	makefile

.if defined(NOPORTDOCS)
ALL_TARGET=	mined manual
.else
PORTDOCS=	*
.endif

USE_GMAKE=	yes
REINPLACE_ARGS=	-i ""
MAKE_ARGS=	GMAKE=${GMAKE} CC=${CC:T} OPT="${CFLAGS}"
INSTALL_TARGET=	localinstall

MAN1=		mined.1

PRFX2FIX=	src/makefile.bsd usrshare/conf_user/xinitrc.mined	\
		src/makefile.curses src/mined1.c man/mined.1		\
		usrshare/setup_install/mined.desktop src/makefile.gcc

pre-configure:
.for FILE in ${PRFX2FIX}
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/${FILE}
.endfor

pre-build:
	${MV} ${WRKSRC}/src/mkinclud.cc ${WRKSRC}/src/mkinclud.cc.bak
	${CP} ${WRKSRC}/src/mkinclud.gcc ${WRKSRC}/src/mkinclud.cc
	(if [ ! -f ${WRKSRC}/src/mkinclud.${CC:T} ] ; then	\
	${LN} -sf ${WRKSRC}/src/mkinclud.cc ${WRKSRC}/src/mkinclud.${CC:T} ; \
	fi)
	@${ECHO_MSG}
	@${ECHO_MSG} "Warning: conversion of all keyboard mapping tables may take a long time!"
	@${ECHO_MSG}

post-install:
	${INSTALL_DATA} ${WRKSRC}/usrshare/setup_install/mined.desktop	\
		${DESKTOPDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} * ${DOCSDIR}
	cd ${WRKSRC}/usrshare/package_doc && ${INSTALL_DATA} * ${DOCSDIR}
	@${RM} ${DOCSDIR}/CHANGES ${DOCSDIR}/LICENSE.GNU
.endif
	@${RM} ${DATADIR}/bin/*.bat
	@${RM} -rf ${DATADIR}/doc_user ${DATADIR}/package_doc

.include <bsd.port.mk>
