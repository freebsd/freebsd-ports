# Created by: Cyrille Lefevre <cyrille.lefevre@laposte.net>

PORTNAME=	gzip
PORTVERSION=	1.11
CATEGORIES=	archivers
MASTER_SITES=	GNU

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Compression utility designed to be a replacement for compress

LICENSE=	GPLv3+

USES=		cpe charsetfix makeinfo tar:xz
GNU_CONFIGURE=	yes

CONFLICTS_INSTALL=	zutils # bin/zcat bin/zcmp bin/zdiff bin/zgrep

INFO=		gzip
CPE_VENDOR=	gnu

PORTDOCS=	AUTHORS COPYING ChangeLog ChangeLog-2007 INSTALL NEWS README \
		THANKS TODO

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
