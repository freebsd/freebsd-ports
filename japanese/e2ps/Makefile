# Created by: Daisuke Kawahara <kawahara@pine.kuee.kyoto-u.ac.jp>
# $FreeBSD$

PORTNAME=	e2ps
PORTVERSION=	4.34
CATEGORIES=	japanese print
MASTER_SITES=	http://wt1.ld.infoseek.co.jp/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text file to postscript converter (with Japanese support)

USES=		tar:bzip2
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

PLIST_FILES=	bin/e2ps bin/e2lpr
PORTDOCS=	README.euc README.english

OPTIONS_DEFINE=	DOCS

post-patch:
		cd ${WRKSRC} && \
		mv ps-font.c ps-font.c.orig && \
		${SED} -e '/Times-Roman$$/,/^Gothic-Medium.Katakana$$/{s,$$,\\,;}' ps-font.c.orig > ps-font.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/e2ps ${STAGEDIR}${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/e2ps ${STAGEDIR}${PREFIX}/bin/e2lpr
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
