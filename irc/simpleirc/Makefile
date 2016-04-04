# Created by: Dennis Herrmann <adox@mcx2.org>
# $FreeBSD$

PORTNAME=	simpleirc
PORTVERSION=	1.2
CATEGORIES=	irc
MASTER_SITES=	http://dl.suckless.org/tools/ \
		LOCAL/dhn
DISTNAME=	sic-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extremely simple IRC client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PLIST_FILES=	bin/simpleirc man/man1/simpleirc.1.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
