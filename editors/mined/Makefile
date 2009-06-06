# New ports collection makefile for:	mined
# Date created:		24 December 2004
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	mined
PORTVERSION=	2000.15.3
CATEGORIES=	editors
MASTER_SITES=	http://towo.net/mined/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Text mode editor with Unicode support

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

.if defined(NOPORTDOCS)
ALL_TARGET=	mined manual
.else
PORTDOCS=	*
.endif

USE_GMAKE=	yes
MAKEFILE=	makefile
MAKE_SHELL=	${LOCALBASE}/bin/bash	# To avoid "shift: can't shift that many"
REINPLACE_ARGS=	-i ""
MAKE_ARGS=	GMAKE=${GMAKE} CC=${CC:T} OPT="${CFLAGS}"
INSTALL_TARGET=	localinstall

NOMANCOMPRESS=	yes
MAN1=		mined.1 minmacs.1 mpico.1 mstar.1 umined.1 uterm.1 xmined.1

PRFX2FIX=	src/makefile.bsd usrshare/conf_user/xinitrc.mined	\
		src/makefile.curses src/mined1.c man/mined.1		\
		usrshare/setup_install/mined.desktop src/makefile.gcc

pre-configure:
.for FILE in ${PRFX2FIX}
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/${FILE}
.endfor
	${REINPLACE_CMD} -e 's|#! ${SH}|#! ${MAKE_SHELL}|' ${WRKSRC}/makemined

pre-build:
	${MV} ${WRKSRC}/src/mkinclud.cc ${WRKSRC}/src/mkinclud.cc.bak
	${CP} ${WRKSRC}/src/mkinclud.gcc ${WRKSRC}/src/mkinclud.cc
	(if [ ! -f ${WRKSRC}/src/mkinclud.${CC:T} ] ; then	\
	${LN} -sf ${WRKSRC}/src/mkinclud.cc ${WRKSRC}/src/mkinclud.${CC:T} ; \
	fi)

post-install:
	${MKDIR} ${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/usrshare/setup_install/mined.desktop	\
		${DESKTOPDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} * ${DOCSDIR}
	cd ${WRKSRC}/usrshare/package_doc && ${INSTALL_DATA} * ${DOCSDIR}
	@${RM} ${DOCSDIR}/CHANGES ${DOCSDIR}/LICENSE.GNU
.endif
#	@${RM} ${DATADIR}/bin/*.bat
	@${RM} -rf ${DATADIR}/doc_user ${DATADIR}/package_doc

.include <bsd.port.mk>
