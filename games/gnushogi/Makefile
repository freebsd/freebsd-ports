PORTNAME=	gnushogi
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU version of Shogi
WWW=		http://www.cs.caltech.edu/~mvanier/hacking/gnushogi/gnushogi.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=		yes
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS INFO
OPTIONS_DEFAULT=	INFO

INFO_USES=		makeinfo
INFO_INFO=		gnushogi

post-extract-INFO-on:
	-@${RM} ${WRKSRC}/doc/gnushogi.info*

post-patch:
	@${REINPLACE_CMD} -e '/<sys\/file.h>/d' \
		${WRKSRC}/gnushogi/*dsp.c

pre-build-INFO-on:
	cd ${WRKSRC}/doc && makeinfo --no-split gnushogi

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/gnushogi/gnushogi ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/doc/gnushogi.6 ${STAGEDIR}${PREFIX}/share/man/man6
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/gnushogi/gnushogi.bbk ${STAGEDIR}${DATADIR}

do-install-INFO-on:
	@${INSTALL_DATA} ${WRKSRC}/doc/gnushogi.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/BOOKFILES ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/PORTING ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/*.gam ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/*.rules ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
