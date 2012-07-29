# New ports collection makefile for:	simpleirc
# Date created:		24. Dez 2008
# Whom:			Dennis Herrmann <adox@mcx2.org>
#
# $FreeBSD$
#

PORTNAME=	simpleirc
PORTVERSION=	1.1
CATEGORIES=	irc
MASTER_SITES=	http://dl.suckless.org/tools/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dhn
DISTNAME=	sic-${PORTVERSION}

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Extremely simple IRC client

MAN1=		simpleirc.1
PLIST_FILES=	bin/simpleirc
PORTDOCS=	README LICENSE

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/LICENSE ${DOCSDIR}
.endif

.include <bsd.port.mk>
