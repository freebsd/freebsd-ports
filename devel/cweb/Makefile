# New ports collection makefile for:	cweb
# Date created:		10 Feb 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cweb
PORTVERSION=	3.64
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	web/c_cpp/cweb

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Literate programming tools for the C language

NO_WRKSUBDIR=	yes

MAN1=		cweb.1

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/cweb.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ctangle ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/cweave ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cweb.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/c++lib.w ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cweb.el ${PREFIX}/share/emacs/site-lisp
	@${MKDIR} ${PREFIX}/share/texmf/tex/generic/misc
	${INSTALL_DATA} ${WRKSRC}/cwebmac.tex \
		${PREFIX}/share/texmf/tex/generic/misc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/cwebman.tex ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
