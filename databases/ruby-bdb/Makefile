PORTNAME=	bdb
PORTVERSION=	0.6.6
PORTREVISION=	8
CATEGORIES=	databases ruby
MASTER_SITES=	ftp://ftp.idaemons.org/pub/distfiles/ruby/ \
		http://idaemons.org/distfiles/ruby/ \
		LOCAL/knu
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby interface to Oracle Berkeley DB revision 2 or later

LICENSE=	RUBY

BROKEN_RUBY32=	yes

BUILD_DEPENDS=	rubygem-rdoc>=0.a:devel/rubygem-rdoc

USES=		bdb shebangfix tar:bzip2
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

SHEBANG_FILES=	examples/basic.rb examples/cats.rb examples/cursor.rb \
		examples/func.rb examples/join.rb examples/lock.rb \
		examples/log.rb examples/queue.rb examples/recno.rb \
		examples/record.rb examples/replication/base/b.rb \
		examples/replication/base/cl.rb examples/replication/base/ma.rb \
		examples/replication/base/mc.rb examples/replication/base/op.rb \
		examples/replication/mgr/b.rb examples/txn.rb examples/zeroc.rb

CONFIGURE_ARGS=	--with-db-include=${BDB_INCLUDE_DIR} \
		--with-db-lib=${BDB_LIB_DIR}
ALL_TARGET=	all rdoc
INSTALL_TARGET=	site-install

DOCS=		Changes README.en bdb.rd docs/*.rd
DOCSDIR=	${RUBY_MODDOCDIR}
EXAMPLESDIR=	${RUBY_MODEXAMPLESDIR}
SHAREMODE=	0644
PLIST_FILES=	${RUBY_SITEARCHLIBDIR}/bdb.so
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${RM} ${WRKSRC}/docs/*.orig

post-install:
	${STRIP_CMD} ${STAGEDIR}${RUBY_SITEARCHLIBDIR}/bdb.so

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/doc
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/docs/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/doc)

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} "! -empty")

do-test:
	@${MKDIR} ${BUILD_WRKSRC}/tmp
	(cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test)

.include <bsd.port.mk>
