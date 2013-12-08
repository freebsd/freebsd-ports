# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cweb
PORTVERSION=	3.64a.a
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	web/c_cpp/cweb
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.([a-z])$/\1/}

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	Literate programming tools for the C language

NO_WRKSUBDIR=	yes

MAKE_ARGS=	CWEBINPUTS="${DATADIR}" \
		CFLAGS="${CFLAGS}" \
		LINKFLAGS="" \
		CC="${CC}"

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/cweb.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ctangle ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/cweave ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cweb.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/c++lib.w ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/cweb.el ${STAGEDIR}${PREFIX}/share/emacs/site-lisp
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/texmf/tex/generic/misc
	${INSTALL_DATA} ${WRKSRC}/cwebmac.tex \
		${STAGEDIR}${PREFIX}/share/texmf/tex/generic/misc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/cwebman.tex ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
