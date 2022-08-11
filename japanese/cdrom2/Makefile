PORTNAME=	cdrom2
PORTVERSION=	1996.06.16
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://www.nerimadors.or.jp/~jiro/cdrom2/
DISTNAME=	euc
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to lookup CD-ROM dictionaries

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/cdgaiji bin/cdrom2 lib/cdrom2/kojien3.tbl \
		lib/cdrom2/ruigo.tbl
PORTDOCS=	errata.doc gaiji.txt index.doc install.doc kekka.txt \
		kojien3.doc menu.doc readers.doc readme.doc readme.org \
		ruigo.doc x_option.doc

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

do-configure:
	@${ECHO_MSG} "Copying custom Makefile."
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
