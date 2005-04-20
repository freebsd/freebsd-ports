# New ports collection makefile for:	PCSC-ruby
# Date created:		27 Dec 2001
# Whom:			Toni Andjelkovic <toni@soth.at>
#
# $FreeBSD$
#

PORTNAME=	pcsc-lite
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	http://soth.at/PCSC-ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	PCSC-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	toni@soth.at
COMMENT=	Ruby extension for the UNIX PC/SC Lite API (MUSCLE)

LIB_DEPENDS=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite

BROKEN=		"Does not compile with new pcsc-lite. Port will be updated soon."

USE_RUBY=	yes
RUBY_VER=	1.8
CONFIGURE_ARGS+=	--with-pcsclite-dir="${PREFIX}"
USE_RUBY_EXTCONF=	yes
RUBY_SETUP=	install.rb

WRKSRC=		${WRKDIR}/PCSC-ruby

DOCS=		README.txt
EXAMPLES=	examples/test.rb examples/pcsclient.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${EXAMPLES}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
.endif

.include <bsd.port.mk>
