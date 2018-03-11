# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	fastjar
PORTVERSION=	0.93.20060808
PORTREVISION=	1
CATEGORIES=	archivers java
MASTER_SITES=	LOCAL/maho/fastjar

MAINTAINER=	java@FreeBSD.org
COMMENT=	Version of JDK's `jar' command written entirely in C

LICENSE=	GPLv2

USES=		gmake makeinfo perl5 tar:bzip2
USES_PERL5=	build
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
PORTDOCS=	CHANGES ChangeLog NEWS README
PLIST_FILES=	bin/fastjar bin/grepjar \
		man/man1/fastjar.1.gz \
		man/man1/grepjar.1.gz

INFO=		fastjar

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
