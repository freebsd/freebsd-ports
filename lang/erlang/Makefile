# New ports collection makefile for:	erlang
# Date created:		11 Dec 1998
# Whom:			ruslan@shevchenko.kiev.ua
#
# $FreeBSD$
#

PORTNAME=	erlang
PORTVERSION=	r14b02
PORTEPOCH=	1
CATEGORIES=	lang parallel java
MASTER_SITES=	http://www.erlang.org/download/:erlangorg		\
		http://erlang.stacken.kth.se/download/:erlangorg	\
		http://www.csd.uu.se/ftp/mirror/erlang/download/:erlangorg \
		http://www.erlang.se/doc/:erlangse			\
		http://www.erlang.se/publications/:publications		\
		http://www.sics.se/~joe/thesis/:joe			\
		${MASTER_SITE_LOCAL:S/$/:local/:S,%SUBDIR%/,olgeni/,}
DISTNAME=	otp_src_R14B02
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:erlangorg	\
		${ERLANG_MAN}:erlangorg			\
		${ERLANG_DOCS}:erlangorg		\
		${DOC_DISTFILES}
DOC_DISTFILES=	armstrong_thesis_2003.pdf:joe		\
		bjarnelic.pdf:publications		\
		erlang-book-part1.pdf:erlangorg		\
		master_thesis_patterns.pdf:local	\
		mnesia_overview.pdf:publications	\
		programming_rules.pdf:erlangse
DIST_SUBDIR=	erlang
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	http://www.erlang.org/download/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A functional programming language from Ericsson

CONFLICTS?=	erlang-lite-r[0-9]*

SUB_FILES=	pkg-message
SUB_LIST=	TOOLS_VSN=${TOOLS_VSN}

OPTIONS=	JAVA	"Enable Java applications"	on \
		X11	"Enable X11 support"		on \
		WX	"Enable WX extensions"		on \
		ODBC	"Enable ODBC"			on \
		SMP	"Enable SMP"			on

.include <bsd.port.pre.mk>

# The Java applications that are part of the Erlang distribution are
# not strictly necessary - it is included for completeness sake. A
# problem with the Erlang build procedure is that it only checks if
# javac is in the regular path - and then assumes that all of the jdk
# utilities is in the path as well. The only way to make sure that
# this is the case (that I could think of at least) was to make sure
# ${JAVA_HOME}/bin is added to the PATH, using the *_ENV macros.

.if !defined(WITHOUT_JAVA)
USE_JAVA=	yes
JAVA_VERSION=	1.4+
# Make sure ${JAVA_HOME}/bin is in the path
CONFIGURE_ENV+=	PATH=${PATH}:${JAVA_HOME}/bin
MAKE_ENV+=	PATH=${PATH}:${JAVA_HOME}/bin
SCRIPT_ENV+=	PATH=${PATH}:${JAVA_HOME}/bin
.endif

.if !defined(WITHOUT_X11)
USE_TK_RUN=	yes
.if !defined(WITHOUT_WX)
USE_WX=		2.8+
WX_COMPS=	wx contrib
WX_UNICODE=	yes
CONFIGURE_ARGS+=--with-wx-config=${WX_CONFIG}
.endif
.endif

USE_GMAKE=	yes
USE_PERL5=	yes
USE_RC_SUBR=	epmd.sh
GNU_CONFIGURE=	yes
ONLY_FOR_ARCHS=	i386 amd64 sparc64 powerpc
REINPLACE_ARGS=	-i
MAKE_JOBS_UNSAFE=	yes

.if (${OSVERSION} < 700000)
USE_GCC=	4.2+
.endif

.if !defined(WITHOUT_ODBC)
DRIVER_MANAGER?=	iodbc
.if ${DRIVER_MANAGER} == "unixodbc"
LIB_DEPENDS+=		odbc.1:${PORTSDIR}/databases/unixODBC
.else # assume we're using iodbc
LIB_DEPENDS+=		iodbc.3:${PORTSDIR}/databases/libiodbc
.endif
.endif

ERLANG_MAN=	otp_doc_man_R14B02.tar.gz
.if !defined(NOPORTDOCS)
ERLANG_DOCS=	otp_doc_html_R14B02.tar.gz
.endif
ERLANG_PLIST=	${WRKDIR}/pkg-plist

# enabling --enable-smp-support crashes the OS when
# net_kernel:start([node_name, shortnames]) invoked repeatedly

.if !defined(WITHOUT_SMP)
CONFIGURE_ARGS+=--enable-threads --enable-dynamic-ssl-lib --enable-sctp --enable-smp-support
.else
CONFIGURE_ARGS+=--enable-threads --enable-dynamic-ssl-lib --enable-sctp
.endif

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
PLIST_SUB+=	ERTS_VSN=${ERTS_VSN} TOOLS_VSN=${TOOLS_VSN}

.if ${ARCH} == i386
MAKE_ARGS+=	ARCH=x86
.endif

# The man-pages are put (in spite of FreeBSD's port convention) in a private
# subdir. This is to avoid cluttering up the man page name space. Also the
# Erlang man pages are more of internal documentation using the man format than
# actual system man pages. (erl.1 and epmd.1 perhaps being the exception).

NO_MANCOMPRESS=	yes

MAN1PREFIX=	${PREFIX}/lib/erlang
MAN3PREFIX=	${PREFIX}/lib/erlang
MAN4PREFIX=	${PREFIX}/lib/erlang
MAN6PREFIX=	${PREFIX}/lib/erlang

pre-configure:
	@${REINPLACE_CMD} -e 's#%%CFLAGS%%#${CFLAGS}#g' ${WRKSRC}/lib/wx/configure

# Check if ${JAVAC} exists.
.if !defined(WITHOUT_JAVA)
	@if [ ! -x ${JAVAC} ]; then \
		${ECHO_MSG} ">> Error: cannot find ${JAVAC}."; \
		exit 1; \
	fi
.endif

# If X11 is not used, skip the gs application.
.if defined(WITHOUT_X11)
	@${ECHO_CMD} "WITHOUT_X11 defined" > ${WRKSRC}/lib/gs/SKIP
.endif

# If ODBC is not used, skip the odbc application.
.if defined(WITHOUT_ODBC)
	@${ECHO_CMD} "WITHOUT_ODBC defined" > ${WRKSRC}/lib/odbc/SKIP
.endif

# Install documentation. (HTML docs need to be in same dir as the
# rest, not in share/doc/erlang as it should, because of relative
# links in the documentation.
post-install:
	@${LN} -sf ${PREFIX}/lib/erlang/lib/erl_interface-*/bin/erl_call ${PREFIX}/bin/erl_call
	@for SECTION in 1 3 4 6; do \
		${TAR} --unlink -xzpf ${DISTDIR}/${DIST_SUBDIR}/${ERLANG_MAN} \
			-C ${PREFIX}/lib/erlang \
			"man/man$${SECTION}/*.$${SECTION}" || ${TRUE}; \
	done
	@${RM} -rf ${PREFIX}/lib/erlang/man/cat?
.if !defined(NOPORTDOCS)
	@${TAR} --unlink -xzpf ${DISTDIR}/${DIST_SUBDIR}/${ERLANG_DOCS} \
		-C ${PREFIX}/lib/erlang
	@${INSTALL_DATA} ${WRKSRC}/lib/dialyzer/doc/*.txt \
		${PREFIX}/lib/erlang/lib/dialyzer-*/doc/

	@${MKDIR} ${PREFIX}/share/doc/erlang
.for FILE in ${DOC_DISTFILES}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$$(expr ${FILE} : '\([^:]*\)') ${PREFIX}/share/doc/erlang
.endfor
.endif
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/erlang
	@${CHMOD} -R o+rX-w,g+rX-w ${PREFIX}/lib/erlang

# All non-library files.

	@cd ${PREFIX}; ${FIND} lib/erlang/* -type d -empty \
		| ${GREP} -v "^lib/erlang/lib" \
		| ${SORT} \
		| ${SED} -e 's#^#@exec ${MKDIR} %D/#g' \
		> ${ERLANG_PLIST}

	@cd ${PREFIX}; ${FIND} lib/erlang/* -type f -o -type l \
		| ${GREP} -v "^lib/erlang/man" \
		| ${GREP} -v "^lib/erlang/lib" \
		| ${SORT} \
		>> ${ERLANG_PLIST}

# Stock OTP libraries.

	@for LIBRARY in ${OTP_LIBS}; do \
		cd ${PREFIX}; ${TEST} -d lib/erlang/lib/$${LIBRARY} \
			&& ${FIND} lib/erlang/lib/$${LIBRARY} -type f -o -type l; \
	done | ${SORT} >> ${ERLANG_PLIST}

# Stock OTP library directories.

	@for LIBRARY in ${OTP_LIBS}; do \
		cd ${PREFIX}; ${TEST} -d lib/erlang/lib/$${LIBRARY} \
			&& ${FIND} lib/erlang/lib/$${LIBRARY} -type d -empty \
			| ${SED} -e 's#^#@exec ${MKDIR} %D/#g'; \
	done | ${SORT} >> ${ERLANG_PLIST}

	@for LIBRARY in ${OTP_LIBS}; do \
		cd ${PREFIX}; ${TEST} -d lib/erlang/lib/$${LIBRARY} \
			&& ${FIND} lib/erlang/lib/$${LIBRARY} -type d \
			| ${SED} -e 's/^/@dirrm /g'; \
	done | ${SORT} -r >> ${ERLANG_PLIST}

# Other directories.

	@cd ${PREFIX}; ${FIND} lib/erlang/* -type d | ${SORT} -r \
		| ${GREP} -v "^lib/erlang/man" \
		| ${GREP} -v "^lib/erlang/lib" \
		| ${SED} -e 's/^/@dirrm /g' \
		>> ${ERLANG_PLIST}

	@${ECHO_CMD} "r ${TMPPLIST}"		> ${WRKDIR}/ex.script
	@${ECHO_CMD} "/Insert PLIST here"	>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "d"			>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "r ${ERLANG_PLIST}"	>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "x!"			>> ${WRKDIR}/ex.script
	@cd ${WRKDIR}; ex < ex.script
	@${CAT} ${PKGMESSAGE}

buildplt:
	@${ECHO_CMD} =====================================================
	@${ECHO_CMD} WARNING: building a full PLT may literally take hours
	@${ECHO_CMD}
	@${ECHO_CMD} You may wish to settle for the standard PLT built by
	@${ECHO_CMD} dialyzer on the first run.
	@${ECHO_CMD} =====================================================
	@cd ${PREFIX}/lib/erlang/lib; ${PREFIX}/bin/dialyzer --verbose --build_plt --output_plt ${HOME}/.dialyzer_plt -c $$(find ${OTP_LIBS} -name ebin -maxdepth 1) || true

.include "Makefile.lib"
.include "Makefile.man"

.include <bsd.port.post.mk>
