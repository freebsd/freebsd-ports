PORTNAME=	skk-tools
DISTVERSION=	1.3.4-40
DISTVERSIONSUFFIX=	-g7bfccbc
PORTEPOCH=	1
CATEGORIES=	japanese

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Jisyo-tools for the SKK Japanese-input software
WWW=		https://github.com/skk-dev/skktools

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome pkgconfig python:run shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	skk-dev
GH_PROJECT=	skktools

USE_GNOME=	glib20
SHEBANG_FILES=	skk2cdb.py

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-skkdic-expr2

PORTSCOUT=	skipv:start

PLIST_FILES=	bin/skkdic-count bin/skkdic-expr bin/skkdic-expr2 \
		bin/skkdic-sort bin/skk2cdb
PORTDOCS=	FAQ.md README.md README.skkdic-expr2.md

OPTIONS_DEFINE=		DIFF DOCS
DIFF_DESC=		Install skkdic-diff (lang/gauche dependency)
DIFF_RUN_DEPENDS=	gosh:lang/gauche
DIFF_PLIST_FILES=	bin/skkdic-diff
DIFF_PORTDOCS=		README.skkdic-diff.md
DIFF_VARS=		SHEBANG_FILES+=skkdic-diff.scm SHEBANG_LANG=gosh

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/skk2cdb.py ${STAGEDIR}${PREFIX}/bin/skk2cdb

post-install-DIFF-on:
	${INSTALL_SCRIPT} ${WRKSRC}/skkdic-diff.scm \
		${STAGEDIR}${PREFIX}/bin/skkdic-diff

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/READMEs && \
		${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
