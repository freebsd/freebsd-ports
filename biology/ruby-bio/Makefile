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

OPTIONS_DEFINE=	XMLPARSER BDB4 MYSQL PGSQL DOCS
XMLPARSER_DESC=	xmlparser support for faster Blast processing
BDB4_DESC=	bdb4 support for faster flat file indexing

OPTIONSFILE=	${PORT_DBDIR}/ruby-${PORTNAME}/options

USES=	shebangfix
USE_RUBY=	yes
USE_RUBY_SETUP=	yes
SHEBANG_FILES=	sample/biofetch.rb
ruby_OLD_CMD=	/usr/proj/bioruby/bin/ruby

XML_PARSER_RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/xmlparser.so:${PORTSDIR}/textproc/ruby-xmlparser
BDB4_RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb
MYSQL_RUN_DEPENDS=	${RUBY_SITELIBDIR}/DBD/Mysql/Mysql.rb:${PORTSDIR}/databases/ruby-dbd_mysql
PGSQL_RUN_DEPENDS=	${RUBY_SITELIBDIR}/DBD/Pg/Pg.rb:${PORTSDIR}/databases/ruby-dbd_pg

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
