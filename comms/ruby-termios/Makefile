# New ports collection makefile for:	ruby-termios
# Date created:		30 August 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	termios
PORTVERSION=	0
CATEGORIES=	comms ruby
MASTER_SITES=	http://arika.org/pub/Tools/Ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

post-patch:
	${RUBY} -i -pe 'gsub /ttyS\d/, "cuaa0"' ${WRKSRC}/test/*.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${CP} -R ${WRKSRC}/test/*.rb ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${RUBY_DOCDIR}/${PORTNAME}/
.endif

.include <bsd.port.mk>
