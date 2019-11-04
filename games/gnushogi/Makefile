# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	gnushogi
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU version of Shogi

USES=		makeinfo
GNU_CONFIGURE=		yes
MAKE_JOBS_UNSAFE=	yes

INFO=		gnushogi

OPTIONS_DEFINE=	DOCS

post-extract:
	-@${RM} ${WRKSRC}/doc/gnushogi.info*

post-patch:
	@${REINPLACE_CMD} -e 's|/lib/gnushogi|/${DATADIR_REL}|g' \
		${WRKSRC}/gnushogi/Makefile.in
	@${REINPLACE_CMD} -e '/HAVE_SETLINEBUF/s|ifdef|ifndef|' \
		${WRKSRC}/gnushogi/gnushogi.h
	@${REINPLACE_CMD} -e '/<sys\/file.h>/d' \
		${WRKSRC}/gnushogi/*dsp.c

pre-build:
	cd ${WRKSRC}/doc && makeinfo --no-split gnushogi

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/gnushogi/gnushogi ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/doc/gnushogi.6 ${STAGEDIR}${MANPREFIX}/man/man6
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/gnushogi/gnushogi.bbk ${STAGEDIR}${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/gnushogi.info ${STAGEDIR}${PREFIX}/${INFO_PATH}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/BOOKFILES ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/PORTING ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/*.gam ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/*.rules ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
