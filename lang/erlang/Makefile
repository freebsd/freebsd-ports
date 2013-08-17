# Created by: ruslan@shevchenko.kiev.ua
# $FreeBSD$

PORTNAME=	erlang
PORTVERSION=	15.b.03.1
PORTREVISION=	1
PORTEPOCH=	3
CATEGORIES=	lang parallel java
MASTER_SITES=	http://www.erlang.org/download/:erlangorg		\
		http://erlang.stacken.kth.se/download/:erlangorg	\
		http://www.csd.uu.se/ftp/mirror/erlang/download/:erlangorg \
		http://www.erlang.se/doc/:erlangse			\
		http://www.erlang.se/publications/:publications		\
		http://www.sics.se/~joe/thesis/:joe			\
		${MASTER_SITE_LOCAL:S/$/:local/:S,%SUBDIR%/,olgeni/,}
DISTNAME=	otp_src_${ERL_RELEASE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:erlangorg	\
		${ERLANG_MAN}:erlangorg
DIST_SUBDIR=	erlang
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	http://www.erlang.org/download

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A functional programming language from Ericsson

WRKSRC=		${WRKDIR}/otp_src_R15B03

ERLANG_LIB=	${PORTNAME}

SUB_FILES=	pkg-message
SUB_LIST=	TOOLS_VSN=${TOOLS_VSN}
PLIST_SUB=	ERLANG_LIB=${ERLANG_LIB}

MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	GCC DOCS GS HIPE JAVA KQUEUE ODBC OPENSSL SCTP SMP THREADS WX DTRACE
OPTIONS_SINGLE=	ODBC
OPTIONS_SINGLE_ODBC=	IODBC UNIXODBC

GCC_DESC=	Use current GCC
HIPE_DESC=	Build native HiPE compiler
KQUEUE_DESC=	Enable Kernel Poll (kqueue) support
SCTP_DESC=	Enable SCTP support
SMP_DESC=	Enable SMP support
WX_DESC=	Enable WX application
GS_DESC=	Enable GS application (deprecated)
DTRACE_DESC=	Enable DTrace support (experimental)

OPTIONS_DEFAULT=SMP OPENSSL THREADS SCTP KQUEUE

ERL_RELEASE=	R${PORTVERSION:S/.//g:U:S/1$/-1/}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	${ERLANG_DOCS}:erlangorg		\
		${DOC_DISTFILES}
DOC_DISTFILES=	armstrong_thesis_2003.pdf:joe		\
		bjarnelic.pdf:publications		\
		erlang-book-part1.pdf:erlangorg		\
		master_thesis_patterns.pdf:local	\
		mnesia_overview.pdf:publications	\
		programming_rules.pdf:erlangse
.endif

# See http://wiki.freebsd.org/DTrace to learn how to enable DTrace
# on your system. You will need to configure STRIP, WITH_CTF and
# CFLAGS in your make.conf before building.

# If you run Erlang and get a message resembling "WARNING: number of
# probes fixed does not match the number of defined probes (54 != 132,
# respectively)" you probably misconfigured DTrace in some way.

.if ${ARCH} == "amd64" && ${PORT_OPTIONS:MDTRACE} && ! ${PORT_OPTIONS:MGCC}
IGNORE=		DTRACE support on amd64 requires GCC option
.endif

.if ${PORT_OPTIONS:MGCC}
USE_GCC?=	yes
.endif

.if ${PORT_OPTIONS:MDTRACE}
CONFIGURE_ARGS+=--with-dynamic-trace=dtrace
.else
CONFIGURE_ARGS+=--without-dynamic-trace
.endif

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-ssl=${OPENSSLBASE}
.else
CONFIGURE_ARGS+=--without-ssl
.endif

.if ${PORT_OPTIONS:MJAVA}
USE_JAVA=	yes
CONFIGURE_ARGS+=--with-javac
CONFIGURE_ENV+=	ac_cv_prog_JAVAC="${JAVAC}"
.else
CONFIGURE_ARGS+=--without-javac
.endif

.if ${PORT_OPTIONS:MHIPE}
CONFIGURE_ARGS+=--enable-hipe
.else
CONFIGURE_ARGS+=--disable-hipe
.endif

.if ${PORT_OPTIONS:MKQUEUE}
CONFIGURE_ARGS+=--enable-kernel-poll
.else
CONFIGURE_ARGS+=--disable-kernel-poll
.endif

.if ${PORT_OPTIONS:MGS}
USE_TK_RUN=	yes
.endif

.if ${PORT_OPTIONS:MWX}
USE_WX=		2.8+
WX_COMPS=	wx contrib
WX_UNICODE=	yes
CONFIGURE_ARGS+=--with-wx-config=${WX_CONFIG}
.endif

USE_GMAKE=	yes
USE_CSTD=	gnu89
USE_PERL5=	yes
USE_RC_SUBR=	epmd
GNU_CONFIGURE=	yes

.if ${PORT_OPTIONS:MODBC}
CONFIGURE_ARGS+=--with-odbc
.if ${PORT_OPTIONS:MUNIXODBC}
LIB_DEPENDS+=	odbc:${PORTSDIR}/databases/unixODBC
.elif ${PORT_OPTIONS:MIODBC}
LIB_DEPENDS+=	iodbc:${PORTSDIR}/databases/libiodbc
.endif
.else
CONFIGURE_ARGS+=--without-odbc
.endif

ERLANG_MAN=	otp_doc_man_${ERL_RELEASE}.tar.gz
ERLANG_DOCS=	otp_doc_html_${ERL_RELEASE}.tar.gz
ERLANG_PLIST=	${WRKDIR}/pkg-plist

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=--enable-threads
.else
CONFIGURE_ARGS+=--disable-threads
.endif

.if ${PORT_OPTIONS:MSCTP}
CONFIGURE_ARGS+=--enable-sctp
.else
CONFIGURE_ARGS+=--disable-sctp
.endif

# enabling --enable-smp-support crashes the OS when
# net_kernel:start([node_name, shortnames]) invoked repeatedly
# TODO verify if it still applies

.if ${PORT_OPTIONS:MSMP}
CONFIGURE_ARGS+=--enable-smp-support
.else
CONFIGURE_ARGS+=--disable-smp-support
.endif

.if ${ARCH} == i386
MAKE_ARGS+=	ARCH=x86
.endif

# The man-pages are put (in spite of FreeBSD's port convention) in a private
# subdir. This is to avoid cluttering up the man page name space. Also the
# Erlang man pages are more of internal documentation using the man format than
# actual system man pages. (erl.1 and epmd.1 perhaps being the exception).

NO_MANCOMPRESS=	yes

MAN1PREFIX=	${PREFIX}/lib/${ERLANG_LIB}
MAN3PREFIX=	${PREFIX}/lib/${ERLANG_LIB}
MAN4PREFIX=	${PREFIX}/lib/${ERLANG_LIB}
MAN6PREFIX=	${PREFIX}/lib/${ERLANG_LIB}

# Install documentation. (HTML docs need to be in same dir as the
# rest, not in share/doc/erlang as it should, because of relative
# links in the documentation.
post-install:
	@${LN} -sf ${PREFIX}/lib/${ERLANG_LIB}/lib/erl_interface-*/bin/erl_call ${PREFIX}/bin/erl_call
	@for SECTION in 1 3 4 6; do \
		${TAR} --unlink -xzpf ${DISTDIR}/${DIST_SUBDIR}/${ERLANG_MAN} \
			-C ${PREFIX}/lib/${ERLANG_LIB} \
			"man/man$${SECTION}/*.$${SECTION}" || ${TRUE}; \
	done
	@${RM} -rf ${PREFIX}/lib/${ERLANG_LIB}/man/cat?
.if ${PORT_OPTIONS:MDOCS}
	@${TAR} --unlink -xzpf ${DISTDIR}/${DIST_SUBDIR}/${ERLANG_DOCS} \
		-C ${PREFIX}/lib/${ERLANG_LIB}
	@${INSTALL_DATA} ${WRKSRC}/lib/dialyzer/doc/*.txt \
		${PREFIX}/lib/${ERLANG_LIB}/lib/dialyzer-*/doc/

	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOC_DISTFILES}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$$(expr ${FILE} : '\([^:]*\)') ${DOCSDIR}
.endfor
.endif
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/${ERLANG_LIB}
	@${CHMOD} -R o+rX-w,g+rX-w ${PREFIX}/lib/${ERLANG_LIB}

# All non-library files.

	@cd ${PREFIX}; ${FIND} lib/${ERLANG_LIB}/* -type d -empty \
		| ${GREP} -v "^lib/${ERLANG_LIB}/lib" \
		| ${SORT} \
		| ${SED} -e 's#^#@exec ${MKDIR} %D/#g' \
		> ${ERLANG_PLIST}

	@cd ${PREFIX}; ${FIND} lib/${ERLANG_LIB}/* -type f -o -type l \
		| ${GREP} -v "^lib/${ERLANG_LIB}/man" \
		| ${GREP} -v "^lib/${ERLANG_LIB}/lib" \
		| ${SORT} \
		>> ${ERLANG_PLIST}

# Stock OTP libraries.

	@for LIBRARY in ${OTP_LIBS}; do \
		cd ${PREFIX}; ${TEST} -d lib/${ERLANG_LIB}/lib/$${LIBRARY} \
			&& ${FIND} lib/${ERLANG_LIB}/lib/$${LIBRARY} -type f -o -type l; \
	done | ${SORT} >> ${ERLANG_PLIST}

# Stock OTP library directories.

	@for LIBRARY in ${OTP_LIBS}; do \
		cd ${PREFIX}; ${TEST} -d lib/${ERLANG_LIB}/lib/$${LIBRARY} \
			&& ${FIND} lib/${ERLANG_LIB}/lib/$${LIBRARY} -type d -empty \
			| ${SED} -e 's#^#@exec ${MKDIR} %D/#g'; \
	done | ${SORT} >> ${ERLANG_PLIST}

	@for LIBRARY in ${OTP_LIBS}; do \
		cd ${PREFIX}; ${TEST} -d lib/${ERLANG_LIB}/lib/$${LIBRARY} \
			&& ${FIND} lib/${ERLANG_LIB}/lib/$${LIBRARY} -type d \
			| ${SED} -e 's/^/@dirrm /g'; \
	done | ${SORT} -r >> ${ERLANG_PLIST}

# Other directories.

	@cd ${PREFIX}; ${FIND} lib/${ERLANG_LIB}/* -type d | ${SORT} -r \
		| ${GREP} -v "^lib/${ERLANG_LIB}/man" \
		| ${GREP} -v "^lib/${ERLANG_LIB}/lib" \
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
	@cd ${PREFIX}/lib/${ERLANG_LIB}/lib; ${PREFIX}/bin/dialyzer --verbose --build_plt --output_plt ${HOME}/.dialyzer_plt -c $$(find ${OTP_LIBS} -name ebin -maxdepth 1) || true

.include "Makefile.lib"
.include "Makefile.man"

.include <bsd.port.mk>
