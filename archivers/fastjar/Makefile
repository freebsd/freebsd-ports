PORTNAME=	fastjar
DISTVERSION=	0.98
CATEGORIES=	archivers java
MASTER_SITES=	SAVANNAH

MAINTAINER=	java@FreeBSD.org
COMMENT=	Version of JDK's `jar' command written entirely in C
WWW=		https://savannah.nongnu.org/projects/fastjar/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake makeinfo

GNU_CONFIGURE=	yes

INFO=		fastjar
PORTDOCS=	CHANGES ChangeLog NEWS README

PLIST_FILES=	bin/fastjar \
		bin/grepjar \
		lib/charset.alias \
		share/man/man1/fastjar.1.gz \
		share/man/man1/grepjar.1.gz

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
