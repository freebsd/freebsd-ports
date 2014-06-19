# Created by: Dennis Herrmann <adox@mcx2.org>
# $FreeBSD$

PORTNAME=	simpleirc
PORTVERSION=	1.2
CATEGORIES=	irc
MASTER_SITES=	http://dl.suckless.org/tools/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dhn
DISTNAME=	sic-${PORTVERSION}

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Extremely simple IRC client

LICENSE=	MIT

PLIST_FILES=	bin/simpleirc man/man1/simpleirc.1.gz
PORTDOCS=	README LICENSE

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/LICENSE ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
