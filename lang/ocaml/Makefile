# New ports collection makefile for:	ocaml
# Date created:		24 December 1996
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	ocaml
PORTVERSION=	3.11.1
PORTREVISION=	0
CATEGORIES=	lang
MASTER_SITES=	http://caml.inria.fr/distrib/${DISTNAME:R}/ \
		ftp://ftp.inria.fr/INRIA/caml-light/${DISTNAME:R}/ \
		ftp://ftp.kurims.kyoto-u.ac.jp/pub/lang/caml-light/${DISTNAME:R}/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
PKGNAMESUFFIX=	${SFX}

MAINTAINER?=	stas@FreeBSD.org
COMMENT?=	The Objective Caml compiler and programming environment

USE_BZIP2=	yes
REINPLACE_ARGS=	-i ""
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
ALL_TARGET=	world.opt
STRIP=
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS=	-prefix ${PREFIX}
OPTIONS=	X11	"Build with X11 support" on \
		TK	"Build LablTk library (requires X11 support)" on \
		THREADS	"Build with Posix threads support" on \
		CMP_LIB	"Install compiler's libraries" off \
		OPT_DEF	"Use system-optimized binaries by default" off

MODOPT=		camlp4o camlp4r ocamlc ocamldep ocamldoc ocamllex ocamlopt
PATTERN=	[[:space:]]*(do|then)?[[:space:]]*)(\$$\(CP\)|cp)([[:space:]]

.include <bsd.port.pre.mk>

MAN1!=	${CAT} ${FILESDIR}/man1
MANN!=	${CAT} ${FILESDIR}/mann
MLINKS!=${CAT} ${FILESDIR}/manlinks

.if !defined(WITHOUT_THREADS)
DEPENDS_ARGS+=	WITH_THREADS=yes
CONFIGURE_ARGS+=-with-pthread
THR_CPP=	${PTHREAD_CFLAGS}
THR_LD=		${PTHREAD_LIBS}
.else
THR_CPP=	#empty
THR_LD=		#empty
CONFIGURE_ARGS+=-no-pthread
.endif

.if !defined(WITHOUT_X11)
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

.if defined(WITHOUT_TK)
PLIST_SUB+=	TK="@comment "
SFX=		-notk
CONFLICTS+=	ocaml-[0-9]* ocaml-nox11-[0-9]*
CONFIGURE_ARGS+=-no-tk
.else
USE_TK=		84+
.include "${PORTSDIR}/Mk/bsd.tcl.mk"
PLIST_SUB+=	TK=""
CONFLICTS+=	ocaml-nox11-[0-9]* ocaml-notk-[0-9]*
CONFIGURE_ARGS+=	-tkdefs \
			"-I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR} ${THR_CPP}" \
			-tklibs "-L${LOCALBASE}/lib ${THR_LD}"
.endif

.if ${ARCH} == sparc64 || ${ARCH} == ia64
BROKEN=	ocamlc.opt seg-faults on ${ARCH}, please try to fix
.endif

post-configure:
# CFLAGS safeness
	@${REINPLACE_CMD} -E \
		-e 's|(BYTECCCOMPOPTS[ \t]*=.*)|\1 ${CFLAGS} ${THR_CPP}|' \
		-e 's|(NATIVECCCOMPOPTS[ \t]*=.*)|\1 ${CFLAGS} ${THR_CPP}|' \
		-e '/^PTHREAD_LINK/s,-pthread,${THR_LD},g' \
		-e 's|gcc|${CC}|g'	\
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

post-install:
	@${TOUCH} ${PREFIX}/lib/ocaml/ocamldoc/custom/.keep
.if !defined(WITHOUT_TK)
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
.if defined(WITH_OPT_DEF)
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
.if defined(WITH_CMP_LIB)
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
	@${ECHO_CMD} "@dirrm lib/ocaml" >> ${TMPPLIST}

.include <bsd.port.post.mk>
