# New ports collection makefile for: ii
# Date created: 	July 13, 2008
# Whom:				Julien Laffaye <kimelto@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ii
PORTVERSION=	1.3
CATEGORIES=	irc
MASTER_SITES=	http://code.suckless.org/dl/tools/ \
		http://laffaye.free.fr/distfiles/

MAINTAINER=	kimelto@gmail.com
COMMENT=	A minimalist FIFO and filesystem-based IRC client

MAN1=	ii.1
PLIST_FILES=	bin/ii
PORTDOCS=	CHANGES README FAQ LICENSE
PORTEXAMPLES=	query.sh

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/CHANGES ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/FAQ ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/LICENSE ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${ECHO_MSG} "installing additional examples to ${EXAMPLESDIR}"
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_MAN} ${WRKSRC}/query.sh ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
