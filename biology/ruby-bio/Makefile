# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	bio
PORTVERSION=	1.4.1
CATEGORIES=	biology ruby
MASTER_SITES=	http://bioruby.org/archive/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	mauricio@arareko.net
COMMENT=	Integrated environment for Bioinformatics written in Ruby

LICENSE=	GPLv2 RUBY
LICENSE_COMB=	dual

BROKEN_RUBY22=	yes

OPTIONS_DEFINE=	XMLPARSER BDB4 MYSQL PGSQL DOCS
XMLPARSER_DESC=	xmlparser support for faster Blast processing
BDB4_DESC=	bdb4 support for faster flat file indexing

NO_ARCH=	yes
USES=	shebangfix
USE_RUBY=	yes
USE_RUBY_SETUP=	yes
SHEBANG_FILES=	sample/biofetch.rb
ruby_OLD_CMD=	/usr/proj/bioruby/bin/ruby

XMLPARSER_RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/xmlparser.so:${PORTSDIR}/textproc/ruby-xmlparser
BDB4_RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb
MYSQL_RUN_DEPENDS=	rubygem-dbd-mysql>=0:${PORTSDIR}/databases/rubygem-dbd-mysql
PGSQL_RUN_DEPENDS=	rubygem-dbd-pg>=0:${PORTSDIR}/databases/rubygem-dbd-pg

post-patch:
	${RUBY} -i -pe 'gsub(%r"(/etc/bioinformatics/)") { "${PREFIX}" + $$1 }' \
		${WRKSRC}/doc/Tutorial.rd \
		${WRKSRC}/lib/bio/io/registry.rb

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bioinformatics
.for f in etc/bioinformatics/seqdatabase.ini
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/${f}.sample
.endfor
	@${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/sample/ ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
	@${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${WRKSRC}/README.rdoc ${STAGEDIR}${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/*.rd ${STAGEDIR}${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/*.rd.ja ${STAGEDIR}${RUBY_MODDOCDIR}/ja/

.include <bsd.port.mk>
