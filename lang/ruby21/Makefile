# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	ruby
PORTVERSION=	${RUBY_PORTVERSION}
PORTREVISION=	${RUBY_PORTREVISION}
PORTEPOCH=	${RUBY_PORTEPOCH}
CATEGORIES=	lang ruby ipv6
MASTER_SITES=	RUBY/${MASTER_SITE_SUBDIR_RUBY}
DISTNAME=	${RUBY_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT?=	Object-oriented interpreted scripting language

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/BSDL
LICENSE_FILE_RUBY=	${WRKSRC}/COPYING

# Using LIB_DEPENDS finds the libffi from gcc which causes problems
BUILD_DEPENDS=	libffi>=0:devel/libffi
LIB_DEPENDS=	libyaml.so:textproc/libyaml
RUN_DEPENDS=	libffi>=0:devel/libffi

CONFIGURE_ARGS=	${RUBY_CONFIGURE_ARGS} \
		--disable-rpath \
		--enable-pthread \
		--enable-shared \
		--with-ruby-version=minor \
		--with-sitedir="${PREFIX}/lib/ruby/site_ruby" \
		--with-vendordir="${PREFIX}/lib/ruby/vendor_ruby"
CONFIGURE_ENV=	debugflags=
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
# Keep this, else ruby will fail to load libraries dependent of libpthread.
LIBS+=		-lpthread -L${LOCALBASE}/lib
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USES=		autoreconf cpe execinfo tar:xz
WRKSRC=		${RUBY_WRKSRC}

RUBY_VER=		2.1
USE_RUBY=		yes
RUBY_NO_BUILD_DEPENDS=	yes
RUBY_NO_RUN_DEPENDS=	yes

OPTIONS_DEFINE=		CAPIDOCS DEBUG DOCS EXAMPLES GMP RDOC
OPTIONS_DEFAULT=	RDOC LIBEDIT
OPTIONS_SINGLE=		EDIT
OPTIONS_SINGLE_EDIT=	LIBEDIT READLINE
OPTIONS_SUB=		yes
CAPIDOCS_DESC=		Build and install C API documents
GMP_DESC=		Use GMP to accelerate Bignum operations
RDOC_DESC=		Build and install Rdoc indexes
EDIT_DESC=		Which line editing lib to use
LIBEDIT_DESC=		Use libedit
READLINE_DESC=		Use libreadline
CAPIDOCS_BUILD_DEPENDS=	doxygen>0:devel/doxygen \
			dot:graphics/graphviz
CAPIDOCS_CONFIGURE_ENABLE=	install-capi
GMP_CONFIGURE_WITH=	gmp
GMP_LIB_DEPENDS=	libgmp.so:math/gmp
LIBEDIT_CONFIGURE_ON=	--enable-libedit --with-libedit-dir=${LOCALBASE}
LIBEDIT_USES=		libedit
RDOC_CONFIGURE_ENABLE=	install-rdoc
READLINE_BUILD_DEPENDS=	readline>=0:devel/readline
READLINE_CONFIGURE_ON=	--disable-libedit --with-readline-dir=${LOCALBASE}
READLINE_RUN_DEPENDS=	readline>=0:devel/readline

CPE_VENDOR=	ruby-lang
CPE_VERSION=	${RUBY_RELVERSION}
CPE_UPDATE=	p${RUBY_PATCHLEVEL}

.include <bsd.port.pre.mk>

# PORTEPOCH/PORTREVISION hack

.if ${PORTEPOCH} != 0
_SUF2=	,${PORTEPOCH}
.endif

.if ${PORTREVISION} != 0
_SUF1=	_${PORTREVISION}
.endif

.if ${OPSYS} == "FreeBSD"
.if exists(/usr/sbin/dtrace) && (${OSVERSION} > 1100032) && (${ARCH} == "amd64" || ${ARCH} == "i386")
CONFIGURE_ARGS+=	--enable-dtrace
.else
CONFIGURE_ARGS+=	--disable-dtrace
.endif
.endif

.if ${ARCH} == "powerpc64"
USE_GCC=	yes
.endif

.if ${ARCH} == "armv6" || ${ARCH} == "armv6hf"
CONFIGURE_ARGS+=	--with-setjmp-type=_setjmp
CONFIGURE_ENV+=	ac_cv_func__setjmp=yes
.endif

.if ${PORT_OPTIONS:MCAPIDOCS}
MAKE_JOBS_UNSAFE=	yes
.endif

.if ${RUBY_VER} == ${RUBY_DEFAULT_VER}
MLINKS=		${RUBY_NAME}.1 ruby.1
PLIST_SUB+=	IF_DEFAULT=""
.else
PKGNAMESUFFIX=	${RUBY_VER:C/\.//}
PLIST_SUB+=	IF_DEFAULT="@comment "
.endif

INSTALLED_SCRIPTS=	irb erb rdoc ri ruby testrb

EXTSAMPLES=	bigdecimal/sample/*.rb

EXTDOCS=	readline/README*		\
		ripper/README			\
		stringio/README			\
		syslog/syslog.txt

# Macros to change variables in rbconfig.rb
RB_SET_CONF_VAR=${SH} -c '${REINPLACE_CMD} -E -e "s,(CONFIG\[\"$$0\"\][[:space:]]*=[[:space:]]*)(\(?)(.*)(\)?),\1\2$$1\4," ${WRKSRC}/rbconfig.rb' --

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's,-l$$pthread_lib,-lpthread,g' \
		-e '/^RUBY_LIB_PATH/s,\.\$$\{TEENY\},,' \
		-e '/^RUBY_SITE_LIB_PATH2/s,\.\$$\{TEENY\},,' \
		-e '/^RUBY_VENDOR_LIB_PATH2/s,\.\$$\{TEENY\},,' \
		${WRKSRC}/configure

	#
	# Eliminate all leftovers
	#
	@${FIND} ${WRKSRC}/ -name "*.orig" -delete

#
# Remove modules we don't want
#
.for d in win32ole
	@${RM} -r ${BUILD_WRKSRC}/ext/${d}
.endfor
# We get rake from ports.
.for d in bin/rake doc/rake lib/rake test/rake man/rake.1 lib/rake.rb
	@${RM} -r ${BUILD_WRKSRC}/${d}
.endfor
# We get the gem executable from ports.
	@${RM} ${BUILD_WRKSRC}/bin/gem

#
# Prepare modules we are wanting to build via external ports
#
.for d in gdbm tk
	@${MV} ${BUILD_WRKSRC}/ext/${d} ${WRKDIR}/
.endfor

post-build:
#
# Hack to allow modules to be installed into separate PREFIX and/or under user
# privilegies
#
	@${RB_SET_CONF_VAR} "prefix" "ENV['PREFIX'] || \3"
	@${RB_SET_CONF_VAR} "INSTALL" "'/usr/bin/install -c'"
	@${RB_SET_CONF_VAR} "INSTALL_PROGRAM" "ENV['RB_USER_INSTALL'] ? '${INSTALL} ${COPY} ${STRIP} -m ${BINMODE}' : '${INSTALL_PROGRAM}'"
	@${RB_SET_CONF_VAR} "INSTALL_SCRIPT" "ENV['RB_USER_INSTALL'] ? '${INSTALL} ${COPY} -m ${BINMODE}' : '${INSTALL_SCRIPT}'"
	@${RB_SET_CONF_VAR} "INSTALL_DATA" "ENV['RB_USER_INSTALL'] ? '${INSTALL} ${COPY} -m ${SHAREMODE}' : '${INSTALL_DATA}'"

post-build-CAPIDOCS-on:
	@${FIND} ${WRKSRC}/doc -type d -empty -delete

pre-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITEARCHLIBDIR}
	${MKDIR} ${STAGEDIR}${RUBY_VENDORARCHLIBDIR}

pre-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${RUBY_DOCDIR}

pre-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${RUBY_EXAMPLESDIR}

pre-install-RDOC-on:
	${MKDIR} ${STAGEDIR}${RUBY_RIDIR}
	${MKDIR} ${STAGEDIR}${RUBY_SITERIDIR}

post-install:
#
# Link just installed "ruby" to "ruby21", etc.
#
.if ${RUBY_VER} == ${RUBY_DEFAULT_VER}
. for FILE in ${INSTALLED_SCRIPTS}
	${LN} -fs ${FILE}${RUBY_SUFFIX} ${STAGEDIR}${PREFIX}/bin/${FILE}
. endfor
.endif

post-install-DEBUG-off:
#
# XXX: hack to strip ruby binary. Ruby uses its own install script that seems
# bogus to hack.
#
.if defined(STRIP) && ${STRIP} == -s
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${RUBY_NAME}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libruby${RUBY_SHLIBVER}.so.${RUBY_SHLIBVER}
	${FIND} ${STAGEDIR}${RUBY_ARCHLIBDIR} -type f -name '*\.so' -exec ${STRIP_CMD} {} \;
.endif

post-install-DOCS-on:
	# Create all dirs required (":u" isn't avaiable in STABLE yet :-()
	${MKDIR} ${EXTDOCS:C,^([^/]+)/.*,\1,:S,^,${STAGEDIR}${RUBY_DOCDIR}/,}
.for FILE in ${EXTDOCS}
	${INSTALL_DATA} ${WRKSRC}/ext/${FILE} \
		${STAGEDIR}${RUBY_DOCDIR}/${FILE:C,^([^/]+)/.*,\1,}/
.endfor
	@(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${RUBY_DOCDIR}/)
	${INSTALL_DATA} ${WRKSRC}/COPYING*	\
			${WRKSRC}/ChangeLog	\
			${WRKSRC}/LEGAL		\
			${WRKSRC}/README*	\
			${STAGEDIR}${RUBY_DOCDIR}/

post-install-EXAMPLES-on:
	# Create all dirs required (":u" isn't avaiable in STABLE yet :-()
	${MKDIR} ${EXTSAMPLES:C,^([^/]+)/.*,\1,:S,^,${STAGEDIR}${RUBY_EXAMPLESDIR}/,}
.for FILE in ${EXTSAMPLES}
	${INSTALL_DATA} ${WRKSRC}/ext/${FILE} \
		${STAGEDIR}${RUBY_EXAMPLESDIR}/${FILE:C,^([^/]+)/.*,\1,}/
.endfor
	@(cd ${WRKSRC}/sample/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${RUBY_EXAMPLESDIR}/)

regression-test test:
	@(cd ${WRKSRC}; ${MAKE} test)

validate:
	@${MKDIR} ${WRKSRC}/rubyspec
	${RM} -r ${WRKSRC}/rubyspec/*
	(cd ${WRKSRC}/rubyspec && git clone git://github.com/rubyspec/rubyspec.git)
	(cd ${WRKSRC}/rubyspec && git clone git://github.com/rubyspec/mspec.git)
	(cd ${WRKSRC}/rubyspec/rubyspec && ${SETENV} PATH=${WRKSRC}/rubyspec/mspec/bin:${PATH} mspec -t ${PREFIX}/bin/ruby${RUBY_SUFFIX} .)

.include <bsd.port.post.mk>
