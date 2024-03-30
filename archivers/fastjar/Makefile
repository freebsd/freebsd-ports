PORTNAME=	fastjar
PORTVERSION=	0.93.20060808
PORTREVISION=	4
CATEGORIES=	archivers java
MASTER_SITES=	LOCAL/maho/fastjar

MAINTAINER=	java@FreeBSD.org
COMMENT=	Version of JDK's `jar' command written entirely in C
WWW=		https://fastjar.sourceforge.net/

LICENSE=	GPLv2+

USES=		gmake makeinfo perl5 tar:bzip2
USE_PERL5=	build
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

WRKSRC=		${WRKDIR}/${PORTNAME}
PORTDOCS=	CHANGES ChangeLog NEWS README
PLIST_FILES=	bin/fastjar bin/grepjar \
		share/man/man1/fastjar.1.gz \
		share/man/man1/grepjar.1.gz

INFO=		fastjar

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
