# New ports collection makefile for:	erlang
# Date created:		11 Dec 1998
# Whom:			ruslan@shevchenko.kiev.ua
#
# $FreeBSD$
#

PORTNAME=	erlang
PORTVERSION=	r10b5
PORTEPOCH=	1
CATEGORIES=	lang parallel
MASTER_SITES=	http://www.erlang.org/download/        \
		ftp://ftp.erlang.org/pub/download/     \
		http://www.erlang.org/download/        \
		http://erlang.stacken.kth.se/download/ \
		http://www.csd.uu.se/ftp/mirror/erlang/download/
DISTNAME=	otp_src_R10B-5

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${ERLANG_MAN} ${ERLANG_DOCS}
DIST_SUBDIR=	erlang
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A functional programming language from Ericsson

.if !defined(WITHOUT_X11)
RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84
.endif

# Set JAVABINDIR to where you have javac, if different from below
JAVABINDIR?=	${LOCALBASE}/jdk1.4.2/bin
JAVAPORT?=	${JAVABINDIR}/javac:${PORTSDIR}/java/jdk14

ERLANG_MAN=     otp_doc_man_R10B-5.tar.gz
.if !defined(NOPORTDOCS)
ERLANG_DOCS=	otp_doc_html_R10B-5.tar.gz
.endif

USE_GMAKE=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
ONLY_FOR_ARCHS=	i386
REINPLACE_ARGS=	-i

CONFIGURE_TARGET=	# Empty
CONFIGURE_ARGS+=	--enable-threads --enable-hipe --enable-kernel-poll
NOPRECIOUSMAKEVARS=	yes # Prevent exporting of "ARCH"

.include <bsd.port.pre.mk>

.if !exists(${JAVABINDIR}/java)
WITHOUT_JAVA=	yes
.endif

.if !defined(WITHOUT_JAVA)
# The Java applications that are part of the Erlang distribution are
# not strictly necessary - it is included for completeness sake. A
# problem with the Erlang build procedure is that it only checks if
# javac is in the regular path - and then assumes that all of the jdk
# utilities is in the path as well. The only way to make sure that
# this is the case (that I could think of at least) was to make sure
# JAVABINDIR is added to the PATH, using the *_ENV macros.

BUILD_DEPENDS+=  ${JAVAPORT}

# Make sure JAVABINDIR is in the path
CONFIGURE_ENV+= PATH=${PATH}:${JAVABINDIR}
MAKE_ENV+=      PATH=${PATH}:${JAVABINDIR}
SCRIPT_ENV+=    PATH=${PATH}:${JAVABINDIR}
.endif

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
# Check if javac is really in ${JAVABINDIR}.
.if !defined(WITHOUT_JAVA)
	@if [ ! -x ${JAVABINDIR}/javac ]; then \
		${ECHO_MSG} ">> Error: cannot find javac in JAVABINDIR."; \
		${ECHO_MSG} ">> Please configure JAVABINDIR, or use the WITHOUT_JAVA option"; \
		exit 1; \
	fi
.endif

# If X11 is not used, skip the gs application.
.if defined(WITHOUT_X11)
	@${ECHO_CMD} "WITHOUT_X11 defined" > ${WRKSRC}/lib/gs/SKIP
.endif

# Install documentation. (HTML docs need to be in same dir as the
# rest, not in share/doc/erlang as it should, because of relative
# links in the documentation.
post-install:
#	@for SCRIPT in ecc elink ear escript; do \
#		${REINPLACE_CMD} -e "s@ERLANG_EARS=.*@ERLANG_EARS=${LOCALBASE}/lib/erlang/erts-${ERTS_VSN}@" ${LOCALBASE}/bin/$${SCRIPT}; \
#	done

#	@for SCRIPT in ecc elink; do \
#		${REINPLACE_CMD} -e "s@exec .*beam_evm@exec beam_evm@" ${LOCALBASE}/bin/$${SCRIPT}; \
#	done

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
		> ${WRKDIR}/PLIST.lib-erlang

# Stock OTP libraries.

	@for LIBRARY in ${OTP_LIBS}; do \
		cd ${PREFIX} ; ${FIND} lib/erlang/lib/$${LIBRARY} -type f -o -type l; \
	done | ${SORT} >> ${WRKDIR}/PLIST.lib-erlang

# Stock OTP library directories.

	@for LIBRARY in ${OTP_LIBS}; do \
		cd ${PREFIX} ; ${FIND} lib/erlang/lib/$${LIBRARY} -type d -empty \
		    	| ${SED} -e 's#^#@exec mkdir -p %D/#g'; \
	done | ${SORT} >> ${WRKDIR}/PLIST.lib-erlang

	@for LIBRARY in ${OTP_LIBS}; do \
		cd ${PREFIX} ; ${FIND} lib/erlang/lib/$${LIBRARY} -type d \
		    	| ${SED} -e 's/^/@dirrm /g'; \
	done | ${SORT} -r >> ${WRKDIR}/PLIST.lib-erlang

# Other directories.

	@cd ${PREFIX} ; ${FIND} lib/erlang/* -type d | ${SORT} -r \
		| ${GREP} -v "^lib/erlang/man" \
		| ${GREP} -v "^lib/erlang/lib" \
	    	| ${SED} -e 's/^/@dirrm /g' \
		>> ${WRKDIR}/PLIST.lib-erlang

	@${ECHO_CMD} "r ${TMPPLIST}"			> ${WRKDIR}/ex.script
	@${ECHO_CMD} "/Insert PLIST.lib-erlang"		>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "d"				>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "r ${WRKDIR}/PLIST.lib-erlang"	>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "x!"				>> ${WRKDIR}/ex.script
	@${CP} -p ${TMPPLIST} ${TMPPLIST}.pre-lib-erlang
	@cd ${WRKDIR} ; ex < ex.script

.include "Makefile.lib"
.include "Makefile.man"

.include <bsd.port.post.mk>
