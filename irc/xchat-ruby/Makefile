# New ports collection makefile for:	XChat ruby
# Date created:		21 Jun 2008
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	ruby
PORTVERSION=	1.2
CATEGORIES=	irc ruby
MASTER_SITES=	SF/xchat-${PORTNAME}/xchat-${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	xchat-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	An ruby-scripting plugin for XChat

RUN_DEPENDS=	xchat:${PORTSDIR}/irc/xchat

USE_RUBY=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
DOCSRC=		${WRKDIR}/${DISTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
PLIST_FILES=	lib/xchat/plugins/xchat-ruby.so
PORTDOCS=	README ChangeLog
PORTEXAMPLES=	embedify.rb TimerSample.rb JFilter.rb JBanner.rb

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xchat-ruby.so \
		${PREFIX}/lib/xchat/plugins/
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${DOCSRC}/${doc} \
		${DOCSDIR}/
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
.for doc in ${PORTEXAMPLES}
	${INSTALL_DATA} ${DOCSRC}/*/${doc} \
		${EXAMPLESDIR}/
.endfor
.endif

.include <bsd.port.mk>
