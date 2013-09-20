# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	bdb
PORTVERSION=	0.6.6
PORTREVISION=	1
CATEGORIES=	databases ruby
MASTER_SITES=	ftp://ftp.idaemons.org/pub/distfiles/ruby/ \
		http://idaemons.org/distfiles/ruby/ \
		LOCAL/knu
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
PKGNAMESUFFIX=	${WITH_BDB_VER}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby interface to Oracle Berkeley DB revision 2 or later

USE_BDB=	yes
USE_BZIP2=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONSFILE=	${PORT_DBDIR}/ruby-${PORTNAME}/options

USE_RUBY=		yes
USE_RUBY_EXTCONF=	yes
USE_RUBY_RDOC=		yes

CONFIGURE_ARGS=	--with-db-include=${BDB_INCLUDE_DIR} \
		--with-db-lib=${BDB_LIB_DIR}
INSTALL_TARGET=	site-install

DOCS=		Changes README.en bdb.rd docs/*.rd
DOCSDIR=	${RUBY_MODDOCDIR}
EXAMPLESDIR=	${RUBY_MODEXAMPLESDIR}
PLIST_FILES=	%%RUBY_SITEARCHLIBDIR%%/bdb.so
PORTDOCS=	*
PORTEXAMPLES=	*

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
.if ${RUBY_VER} == 2.0
	@${REINPLACE_CMD} -e '/remove_const/d' ${WRKSRC}/src/features.rb
.endif

post-build:
.if ${PORT_OPTIONS:MDOCS}
	(cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} \
	${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} rdoc)
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/doc
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR})
	(cd ${WRKSRC}/docs/doc && ${COPYTREE_SHARE} . ${DOCSDIR}/doc)
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}/
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${EXAMPLESDIR} "! -empty")
.endif

regression-test: build
	@${MKDIR} ${BUILD_WRKSRC}/tmp
	(cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} \
	${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test)

.include <bsd.port.post.mk>
