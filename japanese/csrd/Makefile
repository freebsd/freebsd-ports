# Created by: Satoshi TAOKA <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	csrd
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/csrd/

PATCH_SITES=	http://green.ribbon.to/~ikazuhiro/dic/files/
PATCHFILES=	csrd.c.diff.gz

MAINTAINER=	yasu@utahime.org
COMMENT=	Utility for Shogakukan Random House English-Japanese Dictionary

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/csrd.doc

MAKEFILE=	makefile.unx
MAKE_ARGS=	CC="${CC}"
ALL_TARGET=	csrd

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/csrd %%DATADIR%%/csrd.fmt %%DATADIR%%/csrd.gai \
		%%DATADIR%%/quiet.fmt %%DATADIR%%/quiet.gai

PORTDOCS=	README csrd.doc

SUB_FILES=	pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/csrd ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/csrd.fmt ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/csrd.gai ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/quiet.fmt ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/quiet.gai ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
