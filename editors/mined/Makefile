PORTNAME=	mined
PORTVERSION=	2022.27
CATEGORIES=	editors
MASTER_SITES=	http://towo.net/mined/download/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Text mode editor with Unicode support
WWW=		http://towo.net/mined/

LICENSE=	GPLv3

BUILD_DEPENDS=	${NONEXISTENT}:textproc/UCD:fetch

USES=		desktop-file-utils gmake ncurses
BINARY_ALIAS=	make=${GMAKE}
HAS_CONFIGURE=	yes
MAKEFILE=	makefile
REINPLACE_ARGS=	-i ""
MAKE_ARGS=	GMAKE="${MAKE_CMD}" CC="${CC}" OPT="${CFLAGS}"
INSTALL_TARGET=	localinstall
MAKE_JOBS_UNSAFE=	yes

UCD_VER=	15.0.0
UCD_DISTDIR=	${DISTDIR}/unicode-UCD/${UCD_VER}

OPTIONS_DEFINE=	DOCS
PORTDOCS=	*

PRFX2FIX=	src/makefile.bsd usrshare/conf_user/xinitrc.mined	\
		src/minedaux.c man/mined.1 src/mkinclud.mak		\
		src/makefile.gcc

post-extract:
	${CP} -p ${UCD_DISTDIR}/UCD.zip ${UCD_DISTDIR}/Unihan.zip ${WRKSRC}/src

pre-configure:
.for FILE in ${PRFX2FIX}
	${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/${FILE}
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/usrshare/setup_install/mined.desktop	\
		${STAGEDIR}${DESKTOPDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mined
.for d in cyg win
	${RM} -r ${STAGEDIR}${DATADIR}/setup_install/${d}
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for d in doc_user package_doc
	${MV} ${STAGEDIR}${DATADIR}/${d} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
