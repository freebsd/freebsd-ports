# New ports collection makefile for: ii
# Date created: 	July 13, 2008
# Whom:				Julien Laffaye <kimelto@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ii
PORTVERSION=	1.6
CATEGORIES=	irc
MASTER_SITES=	http://dl.suckless.org/tools/ \
		http://laffaye.free.fr/distfiles/

MAINTAINER=	kimelto@gmail.com
COMMENT=	A minimalist FIFO and filesystem-based IRC client

LICENSE=	MIT

MAN1=		ii.1
PLIST_FILES=	bin/ii
PORTDOCS=	CHANGES README FAQ
PORTEXAMPLES=	query.sh

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ii ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/ii.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
.for DOCFILE in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${DOCFILE} ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${ECHO_MSG} "installing additional examples to ${EXAMPLESDIR}"
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/query.sh ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
