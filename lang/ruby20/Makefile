# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	ruby
PORTVERSION=	${RUBY_PORTVERSION}
PORTREVISION=	${RUBY_PORTREVISION}
PORTEPOCH=	${RUBY_PORTEPOCH}
CATEGORIES=	lang ruby ipv6
MASTER_SITES=		${MASTER_SITE_RUBY}
MASTER_SITE_SUBDIR=	${MASTER_SITE_SUBDIR_RUBY}
DISTNAME=	${RUBY_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT?=	Object-oriented interpreted scripting language

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual

LIB_DEPENDS=	libyaml.so:${PORTSDIR}/textproc/libyaml

# Using LIB_DEPENDS finds the libffi from gcc which causes problems
BUILD_DEPENDS=	libffi>=0:${PORTSDIR}/devel/libffi
RUN_DEPENDS=	libffi>=0:${PORTSDIR}/devel/libffi

GNU_CONFIGURE=	yes
WRKSRC=		${RUBY_WRKSRC}
CONFIGURE_ARGS=	${RUBY_CONFIGURE_ARGS} \
		--enable-shared \
		--enable-pthread \
		--disable-rpath \
		--with-ruby-version=minor \
		--with-sitedir="${PREFIX}/lib/ruby/site_ruby" \
		--with-vendordir="${PREFIX}/lib/ruby/vendor_ruby"
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf

CONFIGURE_ENV+=	LC_ALL=C
MAKE_ENV+=	LC_ALL=C

WRKSRC=		${WRKDIR}/${PORTNAME}-${RUBY_DISTVERSION}

RUBY_VER=		2.0
USE_RUBY=		yes
RUBY_NO_BUILD_DEPENDS=	yes
RUBY_NO_RUN_DEPENDS=	yes

NO_LATEST_LINK=	yes

OPTIONS_DEFINE=		CAPIDOCS DEBUG DOCS EXAMPLES RDOC
OPTIONS_DEFAULT=	RDOC READLINE
OPTIONS_SINGLE=		EDIT
OPTIONS_SINGLE_EDIT=	LIBEDIT READLINE
OPTIONS_SUB=		yes
CAPIDOCS_DESC=		Build and install C API documents
RDOC_DESC=		Build and install Rdoc indexes
EDIT_DESC=		Which line editing lib to use
LIBEDIT_DESC=		Use libedit
READLINE_DESC=		Use libreadline
CAPIDOCS_BUILD_DEPENDS=	doxygen>0:${PORTSDIR}/devel/doxygen \
			dot:${PORTSDIR}/graphics/graphviz
CAPIDOCS_CONFIGURE_OFF=	--disable-install-capi
RDOC_CONFIGURE_OFF=	--disable-install-rdoc

USES=		execinfo cpe tar:bzip2

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

CPPFLAGS+=	-I${LOCALBASE}/include
# Keep this, else ruby will fail to load libraries dependent op libpthread.
LIBS+=		-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.if ${OPSYS} == "FreeBSD"
.if exists(/usr/sbin/dtrace) && \
	((${ARCH} == "i386" && ${OSVERSION} > 1010000) || \
	(${ARCH} == "amd64" && ${OSVERSION} > 903000))
CONFIGURE_ARGS+=	--enable-dtrace
.else
CONFIGURE_ARGS+=	--disable-dtrace
.endif
.endif

CONFIGURE_ENV=	debugflags=

.if ${PORT_OPTIONS:MCAPIDOCS}
MAKE_JOBS_UNSAFE=	yes
.endif

.if ${PORT_OPTIONS:MLIBEDIT}
BUILD_DEPENDS+=	libedit>=0:${PORTSDIR}/devel/libedit
RUN_DEPENDS+=	libedit>=0:${PORTSDIR}/devel/libedit
CONFIGURE_ARGS+=	--enable-libedit --with-libedit-prefix=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MREADLINE}
BUILD_DEPENDS+=	readline>=0:${PORTSDIR}/devel/readline
RUN_DEPENDS+=	readline>=0:${PORTSDIR}/devel/readline
CONFIGURE_ARGS+=	--disable-libedit --with-readline-prefix=${LOCALBASE}
.endif

.if ${RUBY_VER} == ${RUBY_DEFAULT_VER}
MLINKS=		${RUBY_NAME}.1 ruby.1
PLIST_SUB+=	IF_DEFAULT=""
.else
PKGNAMESUFFIX=	${RUBY_VER:C/\.//}
PLIST_SUB+=	IF_DEFAULT="@comment "
.endif

INSTALLED_SCRIPTS=	irb erb rdoc ri ruby testrb

EXTSAMPLES=	bigdecimal/sample/*.rb	\
		curses/hello.rb		\
		curses/rain.rb		\
		curses/view.rb		\
		curses/view2.rb

EXTDOCS=	readline/README*		\
		ripper/README			\
		stringio/README			\
		syslog/syslog.txt

# Macros to change variables in rbconfig.rb
RB_SET_CONF_VAR=${SH} -c '${REINPLACE_CMD} -E -e "s,(CONFIG\[\"$$0\"\][[:space:]]*=[[:space:]]*)(\(?)(.*)(\)?),\1\2$$1\4," ${WRKSRC}/rbconfig.rb' --

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's,-l$$pthread_lib,${PTHREAD_LIBS},g' \
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
	${RM} -rf ${BUILD_WRKSRC}/ext/${d}
.endfor
# We get rake from ports.
.for d in bin/rake doc/rake lib/rake test/rake man/rake.1 lib/rake.rb
	${RM} -rf ${BUILD_WRKSRC}/${d}
.endfor
# We get the gem executable from ports.
	${RM} ${BUILD_WRKSRC}/bin/gem

#
# Prepare modules we are wanting to build via external ports
#
.for d in gdbm tk
	${MV} ${BUILD_WRKSRC}/ext/${d} ${WRKDIR}/
.endfor

post-build:
#
# Hack to allow modules to be installed into separate PREFIX and/or under user
# privilegies
#
	@${RB_SET_CONF_VAR} "prefix" "ENV['PREFIX'] || \3"
	@${RB_SET_CONF_VAR} "INSTALL" "ENV['RB_USER_INSTALL'] ? '/usr/bin/install -c' : '/usr/bin/install -c ${_BINOWNGRP}'"
	@${RB_SET_CONF_VAR} "INSTALL_PROGRAM" "ENV['RB_USER_INSTALL'] ? '${INSTALL} ${COPY} ${STRIP} -m ${BINMODE}' : '${INSTALL_PROGRAM}'"
	@${RB_SET_CONF_VAR} "INSTALL_SCRIPT" "ENV['RB_USER_INSTALL'] ? '${INSTALL} ${COPY} -m ${BINMODE}' : '${INSTALL_SCRIPT}'"
	@${RB_SET_CONF_VAR} "INSTALL_DATA" "ENV['RB_USER_INSTALL'] ? '${INSTALL} ${COPY} -m ${SHAREMODE}' : '${INSTALL_DATA}'"

pre-su-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITEARCHLIBDIR}
	${MKDIR} ${STAGEDIR}${RUBY_VENDORARCHLIBDIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${RUBY_DOCDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${RUBY_EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MRDOC}
	${MKDIR} ${STAGEDIR}${RUBY_RIDIR}
	${MKDIR} ${STAGEDIR}${RUBY_SITERIDIR}
.endif

post-install:
#
# XXX: hack to strip ruby binary. Ruby uses its own install script that seems
# bogus to hack.
#
.if defined(STRIP) && ${STRIP} == -s && ! ${PORT_OPTIONS:MDEBUG}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${RUBY_NAME}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libruby${RUBY_SHLIBVER}.so.${RUBY_SHLIBVER}
	${FIND} ${STAGEDIR}${RUBY_ARCHLIBDIR} -type f -name '*\.so' -exec ${STRIP_CMD} {} \;
.endif

#
# Link just installed "ruby" to "ruby20", etc.
#
.if ${RUBY_VER} == ${RUBY_DEFAULT_VER}
. for FILE in ${INSTALLED_SCRIPTS}
	${LN} -f ${STAGEDIR}${PREFIX}/bin/${FILE}${RUBY_SUFFIX} ${STAGEDIR}${PREFIX}/bin/${FILE}
. endfor
.endif

	# Create all dirs required (":u" isn't avaiable in STABLE yet :-()
	${MKDIR} ${EXTSAMPLES:C,^([^/]+)/.*,\1,:S,^,${STAGEDIR}${RUBY_EXAMPLESDIR}/,}
	${MKDIR} ${EXTDOCS:C,^([^/]+)/.*,\1,:S,^,${STAGEDIR}${RUBY_DOCDIR}/,}
.for FILE in ${EXTSAMPLES}
	${INSTALL_DATA} ${WRKSRC}/ext/${FILE} \
		${STAGEDIR}${RUBY_EXAMPLESDIR}/${FILE:C,^([^/]+)/.*,\1,}/
.endfor
.for FILE in ${EXTDOCS}
	${INSTALL_DATA} ${WRKSRC}/ext/${FILE} \
		${STAGEDIR}${RUBY_DOCDIR}/${FILE:C,^([^/]+)/.*,\1,}/
.endfor
	@(cd ${WRKSRC}/sample/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${RUBY_EXAMPLESDIR}/)
	@(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${RUBY_DOCDIR}/)
	${INSTALL_DATA} ${WRKSRC}/COPYING*	\
			${WRKSRC}/ChangeLog	\
			${WRKSRC}/LEGAL		\
			${WRKSRC}/README*	\
			${STAGEDIR}${RUBY_DOCDIR}/

test:
	@(cd ${WRKSRC}; ${MAKE} test)

validate:
	@${MKDIR} ${WRKSRC}/rubyspec
	rm -rf ${WRKSRC}/rubyspec/*
	(cd ${WRKSRC}/rubyspec && git clone git://github.com/rubyspec/rubyspec.git)
	(cd ${WRKSRC}/rubyspec && git clone git://github.com/rubyspec/mspec.git)
	(cd ${WRKSRC}/rubyspec/rubyspec && env PATH=${WRKSRC}/rubyspec/mspec/bin:${PATH} mspec -t ${PREFIX}/bin/ruby${RUBY_SUFFIX} .)

.include <bsd.port.post.mk>
