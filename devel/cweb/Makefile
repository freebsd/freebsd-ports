PORTNAME=	cweb
PORTVERSION=	4.12.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/ascherer/${PORTNAME}/releases/download/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	Literate programming tools for the C language
WWW=		https://ctan.org/tex-archive/web/c_cpp/cweb

NO_WRKSUBDIR=	yes

MAKE_JOBS_UNSAFE=	yes
MAKE_ARGS=	CWEBINPUTS="${DATADIR}" \
		CFLAGS="${CFLAGS}" \
		LINKFLAGS="" \
		CC="${CC}"

CONFLICTS_INSTALL=	tex-web2c

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/cweb.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ctangle ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/cweave ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cweb.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/c++lib.w ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/cweb.el ${STAGEDIR}${PREFIX}/share/emacs/site-lisp
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/texmf/tex/generic/misc
	${INSTALL_DATA} ${WRKSRC}/cwebmac.tex \
		${STAGEDIR}${PREFIX}/share/texmf/tex/generic/misc
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/cwebman.tex ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
