# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	${GNUSHOGI_PORTNAME}
PORTVERSION=	${GNUSHOGI_PORTVERSION}
CATEGORIES=	games
MASTER_SITES=	${GNUSHOGI_MASTER_SITES}
MASTER_SITE_SUBDIR=	${GNUSHOGI_MASTER_SITE_SUBDIR}
DISTNAME=	${GNUSHOGI_DISTNAME}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GNU version of Shogi

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-x --without-xshogi
MAKE_JOBS_UNSAFE=	yes

INFO=		gnushogi

.include "${.CURDIR}/../../games/gnushogi/Makefile.common"
.include <bsd.port.pre.mk>

post-extract:
	-@${RM} ${WRKSRC}/doc/gnushogi.info*

post-patch:
	@${REINPLACE_CMD} -e 's|/lib/gnushogi|/${DATADIR_REL}|g' \
		${WRKSRC}/gnushogi/Makefile.in
	@${REINPLACE_CMD} -e '/HAVE_SETLINEBUF/s|ifdef|ifndef|' \
		${WRKSRC}/gnushogi/gnushogi.h

pre-build:
	cd ${WRKSRC}/doc && makeinfo --no-split gnushogi

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/gnushogi/gnushogi ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/doc/gnushogi.6 ${STAGEDIR}${MANPREFIX}/man/man6
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/gnushogi/gnushogi.bbk ${STAGEDIR}${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/gnushogi.info ${STAGEDIR}${PREFIX}/info
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/BOOKFILES ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/PORTING ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/*.gam ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/*.rules ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
