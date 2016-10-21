# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	mined
PORTVERSION=	2015.25
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Text mode editor with Unicode support

LICENSE=	GPLv3

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

USES=		desktop-file-utils gmake ncurses
MAKEFILE=	makefile
REINPLACE_ARGS=	-i ""
MAKE_ARGS=	GMAKE="${MAKE_CMD}" CC="${CC}" OPT="${CFLAGS}"
INSTALL_TARGET=	localinstall
MAKE_JOBS_UNSAFE=	yes

PRFX2FIX=	src/makefile.bsd usrshare/conf_user/xinitrc.mined	\
		src/minedaux.c man/mined.1 src/mkinclud.mak		\
		src/makefile.gcc

pre-configure:
.for FILE in ${PRFX2FIX}
	${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/${FILE}
.endfor

pre-build:
	${MV} ${WRKSRC}/src/mkinclud.cc ${WRKSRC}/src/mkinclud.cc.bak
	${CP} ${WRKSRC}/src/mkinclud.gcc ${WRKSRC}/src/mkinclud.cc
	(if [ ! -f ${WRKSRC}/src/mkinclud.${CC:T} ] ; then	\
	${LN} -sf ${WRKSRC}/src/mkinclud.cc ${WRKSRC}/src/mkinclud.${CC:T} ; \
	fi)

post-install:
	${INSTALL_DATA} ${WRKSRC}/usrshare/setup_install/mined.desktop	\
		${STAGEDIR}${DESKTOPDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mined
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} * ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/usrshare/package_doc && ${INSTALL_DATA} * ${STAGEDIR}${DOCSDIR}
	${RM} -r ${STAGEDIR}${DATADIR}/setup_install/cyg
	@${RM} -r ${STAGEDIR}${DOCSDIR}/CHANGES ${STAGEDIR}${DOCSDIR}/LICENCE.GPL
	@${RM} -r ${STAGEDIR}${DATADIR}/doc_user ${STAGEDIR}${DATADIR}/package_doc

.include <bsd.port.mk>
