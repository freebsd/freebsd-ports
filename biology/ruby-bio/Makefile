# New ports collection makefile for:	BioRuby
# Date created:		24 October 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	bio
PORTVERSION=	0.6.2
CATEGORIES=	biology ruby
MASTER_SITES=	http://bioruby.org/archive/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Integrated environment for Bioinformatics written in Ruby

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

post-patch:
	${RUBY} -i -pe 'gsub(%r"(/etc/bioinformatics/)") { "${PREFIX}" + $$1 }' \
		${WRKSRC}/doc/Tutorial.rd.ja \
		${WRKSRC}/lib/bio/io/registry.rb

do-install:
	${MKDIR} ${PREFIX}/etc/bioinformatics
.for f in etc/bioinformatics/seqdatabase.ini
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${f}.sample
	if [ ! -f ${PREFIX}/${f} ]; then \
		${CP} -p ${PREFIX}/${f}.sample ${PREFIX}/${f}; \
	fi
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/sample/ ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${WRKSRC}/README ${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/*.ja ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.mk>
