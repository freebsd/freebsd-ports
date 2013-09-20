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

OPTIONS_DEFINE=	XMLPARSER BDB4 MYSQL PGSQL
XMLPARSER_DESC=	xmlparser support for faster Blast processing
BDB4_DESC=	bdb4 support for faster flat file indexing

OPTIONSFILE=	${PORT_DBDIR}/ruby-${PORTNAME}/options

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXMLPARSER}
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/xmlparser.so:${PORTSDIR}/textproc/ruby-xmlparser
.endif
.if ${PORT_OPTIONS:MBDB4}
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb
.endif
.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	${RUBY_SITELIBDIR}/DBD/Mysql/Mysql.rb:${PORTSDIR}/databases/ruby-dbd_mysql
.endif
.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	${RUBY_SITELIBDIR}/DBD/Pg/Pg.rb:${PORTSDIR}/databases/ruby-dbd_pg
.endif

post-patch:
	${RUBY} -i -pe 'gsub(%r"(/etc/bioinformatics/)") { "${PREFIX}" + $$1 }' \
		${WRKSRC}/doc/Tutorial.rd \
		${WRKSRC}/lib/bio/io/registry.rb

do-install:
	${MKDIR} ${PREFIX}/etc/bioinformatics
.for f in etc/bioinformatics/seqdatabase.ini
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${f}.sample
	if [ ! -f ${PREFIX}/${f} ]; then \
		${CP} -p ${PREFIX}/${f}.sample ${PREFIX}/${f}; \
	fi
.endfor
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/sample/ ${RUBY_MODEXAMPLESDIR}/
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${WRKSRC}/README.rdoc ${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/*.rd ${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/*.rd.ja ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.post.mk>
