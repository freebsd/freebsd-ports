PORTNAME=	epwutil
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/epwutil/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities to manage Japanese EPWING or Electric-Book based CD-ROM

MAKEFILE=	makefile.unx

EPWPROGS=	bookinfo catdump squeeze

PLIST_FILES=	${EPWPROGS:S|^|bin/|} ${EPWPROGS:S|^|man/ja/man1/|:S|$|.1.gz|}
PORTDOCS=	epwutil.doc

OPTIONS_DEFINE=	DOCS

do-install:
.for file in ${EPWPROGS}
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${file}.man \
		${STAGEDIR}${MANPREFIX}/man/ja/man1/${file}.1
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
