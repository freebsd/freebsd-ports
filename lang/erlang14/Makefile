# New ports collection makefile for:	erlang
# Date created:		11 Dec 1998
# Whom:			ruslan@shevchenko.kiev.ua
#
# $FreeBSD$
#

PORTNAME=	erlang
PORTVERSION=	r10b10
PORTEPOCH=	1
CATEGORIES=	lang parallel
MASTER_SITES=	http://www.erlang.org/download/        \
		ftp://ftp.erlang.org/pub/download/     \
		http://www.erlang.org/download/        \
		http://erlang.stacken.kth.se/download/ \
		http://www.csd.uu.se/ftp/mirror/erlang/download/
DISTNAME=	otp_src_R10B-10
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${ERLANG_MAN} ${ERLANG_DOCS}
DIST_SUBDIR=	erlang
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A functional programming language from Ericsson

CONFLICTS?=	erlang-lite-r[0-9]*

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
CONFIGURE_ENV+= PATH=${PATH}:${JAVA_HOME}/bin
MAKE_ENV+=      PATH=${PATH}:${JAVA_HOME}/bin
SCRIPT_ENV+=    PATH=${PATH}:${JAVA_HOME}/bin
.endif

.if !defined(WITHOUT_X11)
USE_TK=		yes
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502102
WITHOUT_ODBC=	yes
.endif

.if !defined(WITHOUT_ODBC)
DRIVER_MANAGER?=        iodbc
.if ${DRIVER_MANAGER} == "unixodbc"
LIB_DEPENDS+=           odbc.1:${PORTSDIR}/databases/unixODBC
.else # assume we're using iodbc
LIB_DEPENDS+=           iodbc.3:${PORTSDIR}/databases/libiodbc
.endif
.endif

ERLANG_MAN=     otp_doc_man_R10B-10.tar.gz
.if !defined(NOPORTDOCS)
ERLANG_DOCS=	otp_doc_html_R10B-10.tar.gz
.endif
ERLANG_PLIST=	${WRKDIR}/pkg-plist

USE_GMAKE=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
ONLY_FOR_ARCHS=	i386 amd64
REINPLACE_ARGS=	-i

CONFIGURE_TARGET=	# Empty
CONFIGURE_ARGS+=	--enable-threads --enable-kernel-poll
.if ${ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-hipe
.endif
NOPRECIOUSMAKEVARS=	yes # Prevent exporting of "ARCH"

CFLAGS+=        -I${LOCALBASE}/include
LDFLAGS+=       -L${LOCALBASE}/lib
CONFIGURE_ENV=  CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
PLIST_SUB+=	ERTS_VSN=${ERTS_VSN}

# The man-pages are put (in spite of FreeBSD's port convention) in a private
# subdir. This is to avoid cluttering up the man page name space. Also the
# Erlang man pages are more of internal documentation using the man format than
# actual system man pages. (erl.1 and epmd.1 perhaps being the exception).

NOMANCOMPRESS=	yes

MAN1PREFIX=	${PREFIX}/lib/erlang
MAN3PREFIX=	${PREFIX}/lib/erlang
MAN4PREFIX=	${PREFIX}/lib/erlang
MAN6PREFIX=	${PREFIX}/lib/erlang

# Workaround for a ./configure recursion bug which leads to INSTALL being
# set to "../../../../[...]"
post-patch:
	@cd ${WRKSRC} && ${CAT} ${FILESDIR}/post-patch-configure | ${PATCH}

pre-configure:
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
	@${LN} -sf ${LOCALBASE}/lib/erlang/lib/erl_interface-*/bin/erl_call ${LOCALBASE}/bin/erl_call
	@${TAR} --unlink -xzpf ${DISTDIR}/${DIST_SUBDIR}/${ERLANG_MAN} \
		-C ${PREFIX}/lib/erlang
	@${RM} -rf ${PREFIX}/lib/erlang/man/cat?
.if !defined(NOPORTDOCS)
	@${TAR} --unlink -xzpf ${DISTDIR}/${DIST_SUBDIR}/${ERLANG_DOCS} \
		-C ${PREFIX}/lib/erlang
.endif
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/erlang
	@${CHMOD} -R o+rX-w,g+rX-w ${PREFIX}/lib/erlang

# All non-library files.

	@cd ${PREFIX} ; ${FIND} lib/erlang/* -type f -o -type l \
		| ${GREP} -v "^lib/erlang/man" \
		| ${GREP} -v "^lib/erlang/lib" \
		| ${SORT} \
		> ${ERLANG_PLIST}

# Stock OTP libraries.

	@for LIBRARY in ${OTP_LIBS}; do \
		cd ${PREFIX} ; ${FIND} lib/erlang/lib/$${LIBRARY} -type f -o -type l; \
	done | ${SORT} >> ${ERLANG_PLIST}

# Stock OTP library directories.

	@for LIBRARY in ${OTP_LIBS}; do \
		cd ${PREFIX} ; ${FIND} lib/erlang/lib/$${LIBRARY} -type d -empty \
		    	| ${SED} -e 's#^#@exec ${MKDIR} %D/#g'; \
	done | ${SORT} >> ${ERLANG_PLIST}

	@for LIBRARY in ${OTP_LIBS}; do \
		cd ${PREFIX} ; ${FIND} lib/erlang/lib/$${LIBRARY} -type d \
		    	| ${SED} -e 's/^/@dirrm /g'; \
	done | ${SORT} -r >> ${ERLANG_PLIST}

# Other directories.

	@cd ${PREFIX} ; ${FIND} lib/erlang/* -type d | ${SORT} -r \
		| ${GREP} -v "^lib/erlang/man" \
		| ${GREP} -v "^lib/erlang/lib" \
	    	| ${SED} -e 's/^/@dirrm /g' \
		>> ${ERLANG_PLIST}

	@${ECHO_CMD} "r ${TMPPLIST}"		> ${WRKDIR}/ex.script
	@${ECHO_CMD} "/Insert PLIST here"	>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "d"			>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "r ${ERLANG_PLIST}"	>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "x!"			>> ${WRKDIR}/ex.script
	@cd ${WRKDIR} ; ex < ex.script

.include "Makefile.lib"
.include "Makefile.man"

.include <bsd.port.post.mk>
