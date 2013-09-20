# Created by: Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
# $FreeBSD$

PORTNAME=	ocaml
PORTVERSION=	3.12.1
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://caml.inria.fr/distrib/${DISTNAME:R}/ \
		ftp://ftp.inria.fr/INRIA/caml-light/${DISTNAME:R}/ \
		ftp://ftp.kurims.kyoto-u.ac.jp/pub/lang/caml-light/${DISTNAME:R}/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
PKGNAMESUFFIX=	${SFX}

MAINTAINER?=	michael.grunewald@laposte.net
COMMENT?=	The Objective Caml compiler and programming environment

USE_BZIP2=	yes
REINPLACE_ARGS=	-i ""
HAS_CONFIGURE=	yes
ALL_TARGET=	world.opt
STRIP=
SSP_UNSAFE=	yes
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS=	-verbose -prefix "${PREFIX}" -cc "${CC}" -as "${AS}" \
		-aspp "${CC} -c" -partialld "${LD} -r"
OPTIONS_DEFINE=	X11 TK THREADS CMP_LIB OPT_DEF
OPTIONS_DEFAULT=	X11 TK THREADS
TK_DESC=	LablTk library (requires X11 support)
CMP_LIB_DESC=	Install compiler's libraries
OPT_DEF_DESC=	Use system-optimized binaries by default

MODOPT=		camlp4o camlp4r ocamlc ocamldep ocamldoc ocamllex ocamlopt
PATTERN=	[[:space:]]*(do|then)?[[:space:]]*)(\$$\(CP\)|cp)([[:space:]]

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == powerpc
ARCH=	power
.endif

.if ${ARCH} == power
PLIST_SUB+=	PROF="@comment "
.else
PLIST_SUB+=	PROF=""
.endif

.include "${FILESDIR}/manfiles"

.if ${PORT_OPTIONS:MTHREADS}
PLIST_SUB+=	THREADS=""
THR_CPP=	${PTHREAD_CFLAGS}
THR_LD=		${PTHREAD_LIBS}
.else
PLIST_SUB+=	THREADS="@comment "
THR_CPP=	#empty
THR_LD=		#empty
CONFIGURE_ARGS+=-no-pthread
.endif

.if ${PORT_OPTIONS:MX11}
PLIST_SUB+=	X11=""
USE_XORG=	x11
CONFIGURE_ARGS+=-x11include ${LOCALBASE}/include -x11lib ${LOCALBASE}/lib
.else
PLIST_SUB+=	X11="@comment "
WITHOUT_TK=	yes
SFX=		-nox11
CONFLICTS+=	ocaml-[0-9]* ocaml-notk-[0-9]*
CONFIGURE_ARGS+=-no-x11
.endif

.if ! ${PORT_OPTIONS:MTK}
PLIST_SUB+=	TK="@comment "
.if ${PORT_OPTIONS:MX11}
SFX=		-notk
CONFLICTS+=	ocaml-[0-9]* ocaml-nox11-[0-9]*
.endif
CONFIGURE_ARGS+=-no-tk
.else
USE_TK=		84+
INVALID_TK_VER =	86
.include "${PORTSDIR}/Mk/bsd.tcl.mk"
PLIST_SUB+=	TK=""
CONFLICTS+=	ocaml-nox11-[0-9]* ocaml-notk-[0-9]*
CONFIGURE_ARGS+=	-tkdefs \
			"-I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR} ${THR_CPP}" \
			-tklibs "-L${LOCALBASE}/lib -ltk${TK_VER:S|.||} \
			-ltcl${TCL_VER:S|.||} ${THR_LD}"
.endif

.if ${ARCH} == sparc64
BROKEN=	ocamlc.opt seg-faults on ${ARCH}, please try to fix
.endif

post-extract:
.if ${ARCH} == power
	${MV} ${WRKSRC}/asmrun/power-elf.S ${WRKSRC}/asmrun/power-bsd.S
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e '\|MKLIB=|s|ar rc|${AR} rc|' \
		-e '\|RANLIB|s|ranlib|${RANLIB}|' \
		-e '\|bytecclinkopts=|s|""|"${LDFLAGS}"|' \
		-e "\|nativecclinkopts=|s|''|\"${LDFLAGS:C/-Wl,//}\"|" \
		-e '\|mksharedlib=|s|$$bytecc|& $$bytecclinkopts|' \
		-e 's|-lbfd -ldl|-lbfd $$dllib|' \
		${WRKSRC}/configure
# don't hardcode gcc for depend target
	@${REINPLACE_CMD} -e 's|gcc|$$(CC)|' \
		${WRKSRC}/*/Makefile \
		${WRKSRC}/*/*/Makefile
.if ${PORT_OPTIONS:MTK}
	@${REINPLACE_CMD} -e 's|/usr/bin/wish|${WISH}|' \
		${WRKSRC}/otherlibs/labltk/examples_labltk/hello.tcl
.endif

post-configure:
# CFLAGS safeness
	@${REINPLACE_CMD} -E \
		-e 's|(BYTECCCOMPOPTS[ \t]*=.*)|\1 ${CFLAGS} ${THR_CPP}|' \
		-e 's|(NATIVECCCOMPOPTS[ \t]*=.*)|\1 ${CFLAGS} ${THR_CPP}|' \
		-e '/^PTHREAD_LINK/s,-pthread,${THR_LD},g' \
		${WRKSRC}/config/Makefile

# INSTALL* safeness (which preserves the correct permissions despite
# user's umask(1)
	@${FIND} ${WRKDIR} -type f -name Makefile -print0 | \
		${XARGS} -0 -n 5 -x ${REINPLACE_CMD} -E \
		-e 's,\$$\(ARCH\),${ARCH:sparc64=sparc},g'	\
		-e 's,^(${PATTERN}+.*INSTALLDIR),\1\$${BSD_INSTALL_DATA} \4,' \
		-e 's,^(${PATTERN}+.*BINDIR),\1\$${BSD_INSTALL_PROGRAM} \4,' \
		-e 's,^(${PATTERN}+.*LIBDIR),\1\$${BSD_INSTALL_DATA} \4,' \
		-e 's,(${PATTERN}+.*(MANDIR|MANODIR|MANEXT)),\1\$${BSD_INSTALL_MAN} \4,'

check test: install
	@cd ${WRKSRC}/testsuite; ${RM} -f _log; for d in tests/* ; do \
	${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} one DIR=$${d} \
	2>&1 | tee -a _log || ${TRUE} ; done ; \
	${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} report

post-install:
	@${TOUCH} ${PREFIX}/lib/ocaml/ocamldoc/custom/.keep
.if ${PORT_OPTIONS:MTK}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/otherlibs/labltk && \
		${COPYTREE_SHARE} examples_labltk ${EXAMPLESDIR} \
		"! -name .cvsignore" && \
		${COPYTREE_SHARE} examples_camltk ${EXAMPLESDIR} \
		"! -name .cvsignore")
.endif

.for PROG in camlp4o.opt camlp4r.opt ocamlc.opt ocamldep.opt ocamldoc.opt \
		ocamllex.opt ocamlopt.opt ocamlrun ocamlyacc
	@${STRIP_CMD} ${PREFIX}/bin/${PROG}
.endfor

# Fix permissions for ld.conf
	@${CHMOD} 644 ${PREFIX}/lib/ocaml/ld.conf

# Do we want .opt version of tools to be the default ?
.if ${PORT_OPTIONS:MOPT_DEF}
. for module in ${MODOPT}
#	First, we save bytecode version
	@${MV} ${PREFIX}/bin/${module} ${PREFIX}/bin/${module}.byte

#	Next make .opt version be the default one (via link)
	@${LN} ${PREFIX}/bin/${module}.opt ${PREFIX}/bin/${module}
	@${ECHO_CMD} "bin/${module}.byte" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${LN} %D/${module}.opt %D/${module}" >> ${TMPPLIST}
. endfor
.endif

# Add compiler's libs if required
.if ${PORT_OPTIONS:MCMP_LIB}
	@${MKDIR}  ${PREFIX}/lib/ocaml/compiler-lib
	@${INSTALL_DATA} ${WRKSRC}/utils/*.cm* ${PREFIX}/lib/ocaml/compiler-lib
	@${INSTALL_DATA} ${WRKSRC}/utils/*.o ${PREFIX}/lib/ocaml/compiler-lib
	@${INSTALL_DATA} ${WRKSRC}/parsing/*.cm* ${PREFIX}/lib/ocaml/compiler-lib
	@${INSTALL_DATA} ${WRKSRC}/parsing/*.o ${PREFIX}/lib/ocaml/compiler-lib
	@${INSTALL_DATA} ${WRKSRC}/typing/*.cm* ${PREFIX}/lib/ocaml/compiler-lib
	@${INSTALL_DATA} ${WRKSRC}/typing/*.o ${PREFIX}/lib/ocaml/compiler-lib
	@${FIND} ${PREFIX}/lib/ocaml/compiler-lib -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm lib/ocaml/compiler-lib" >> ${TMPPLIST}
.endif
	@${ECHO_CMD} "@unexec rmdir "%D/lib/ocaml" 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.post.mk>
