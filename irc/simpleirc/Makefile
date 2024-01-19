PORTNAME=	simpleirc
DISTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://dl.suckless.org/tools/

DISTNAME=	sic-${DISTVERSION}

MAINTAINER=	Clockwork6400@protonmail.com
COMMENT=	Extremely simple IRC client
WWW=		http://www.suckless.org/programs/sic.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PLIST_FILES=	bin/simpleirc share/man/man1/simpleirc.1.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/simpleirc

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
