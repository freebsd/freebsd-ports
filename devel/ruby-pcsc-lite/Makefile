# New ports collection makefile for:	PCSC-ruby
# Date created:		27 Dec 2001
# Whom:			Toni Andjelkovic <toni@ants.at>
#
# $FreeBSD$
#

PORTNAME=	pcsc-lite
PORTVERSION=	0.5
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.ants.at/ruby/PCSC-ruby/dist/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	PCSC-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	toni@ants.at

LIB_DEPENDS=	pcsclite.0:${PORTSDIR}/devel/pcsc-lite

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
RUBY_SETUP=	install.rb

WRKSRC=		${WRKDIR}/PCSC-ruby

DOCS=		README.txt
EXAMPLES=	examples/test.rb examples/pcsclient.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}/
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.for f in ${EXAMPLES}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
