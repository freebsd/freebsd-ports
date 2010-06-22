# New ports collection makefile for:   mlton
# Date created:                1 Oct 2002
# Whom:                        Stephen Weeks <sweeks@sweeks.com>
#
# $FreeBSD$
#

# Because MLton is written in SML, it needs an SML compiler to build.
# It is easiest to use another (earlier) binary version of MLton as
# the SML compiler.  So, this Makefile fetches and installs an
# alread-built version of MLton, BOOT_DIST, to use for bootstrapping.

PORTNAME=	mlton
PORTVERSION=	20070826
PORTREVISION=	7
CATEGORIES=	lang
MASTER_SITES=	http://mlton.org/pages/Download/attachments/ \
		http://mlton.org/pages/Experimental/attachments/ \
		http://www.tbrk.org/distfiles/
DISTFILES=	${BOOT_DIST} ${SRC_DIST}
EXTRACT_ONLY=	${SRC_DIST}

# Other maintainer is Geoffrey Mainland (mainland@apeiron.net)
MAINTAINER=	jesper.louis.andersen@gmail.com
COMMENT=	An optimizing Standard ML compiler

LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash
BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

OPTIONS=	SMLNJ	"Bootstrap with SML/NJ (can take >15 hours)"	off \
		MINGW32	"Add the mingw32 target (requires wine)"	off

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	gsed:${PORTSDIR}/textproc/gsed \
		htmldoc:${PORTSDIR}/textproc/htmldoc \
		latex:${PORTSDIR}/print/teTeX
.else
INSTALL_TARGET=	install-no-docs
ALL_TARGET=	all-no-docs
.endif

SRC_DIST=	${DISTNAME}-1.src.tgz

.if defined(WITH_SMLNJ)
BUILD_DEPENDS+=	smlnj-devel>=110.65:${PORTSDIR}/lang/sml-nj-devel
BOOT_DIST=
MAKE_ENV+=	SMLNJ_DEVEL=yes
.if defined(NOPORTDOCS)
ALL_TARGET=	nj-mlton all-no-docs
.else
ALL_TARGET=	bootstrap-nj
.endif
.else
BOOT_DIST=	${PORTNAME}-${BOOT_VER}-1.${MACHINE_ARCH}-freebsd${OSRELMAJ}.${BOOT_SUF}
MAKE_ENV+=	LD_LIBMAP=libgmp.so.7=libgmp.so.10
.endif

.if defined(WITH_MINGW32)
BUILD_DEPENDS+=	wine:${PORTSDIR}/emulators/wine \
		mingw32-gcc:${PORTSDIR}/devel/mingw32-gcc \
		${LOCALBASE}/mingw32/lib/libgmp.a:${PORTSDIR}/math/mingw32-libgmp4
RUN_DEPENDS+=	mingw32-gcc:${PORTSDIR}/devel/mingw32-gcc \
		${LOCALBASE}/mingw32/lib/libgmp.a:${PORTSDIR}/math/mingw32-libgmp4

PLIST_SUB+=	MINGW32CROSS=""
.else
PLIST_SUB+=	MINGW32CROSS="@comment "
.endif

ONLY_FOR_ARCHS=	i386

MAN1=		mllex.1 mlprof.1 mlton.1 mlyacc.1 mlnlffigen.1
MANCOMPRESSED=	yes

BOOT_WRKSRC=	${WRKDIR}/mlton-bootstrap

USE_GMAKE=	yes
MAKE_ARGS=	DESTDIR='' \
		PATH=${WRKSRC}/build/bin:${BOOT_WRKSRC}/bin:${PATH} \
		PREFIX=${PREFIX}

.if ${ARCH} == "i386"
MLTON_ARCH=	"x86"
.endif

.if ${OSVERSION} >= 700000
OSRELMAJ=
.else
OSRELMAJ=	-6
.endif

BOOT_EXTRACT=	--bzip2
BOOT_SUF=	tbz
BOOT_VER=	20070826

post-extract:
	@${CP} ${FILESDIR}/add-local-cross ${WRKSRC}/bin/
.if defined(WITH_SMLNJ)
	@${CP} ${FILESDIR}/upgrade-basis.sml ${WRKSRC}/mlton/
	@for f in `ls ${FILESDIR}/ml.* ${FILESDIR}/mlb.*`; do \
		${CP} $$f ${WRKSRC}/mlton/front-end/; \
	done
	@for f in `ls ${FILESDIR}/yacc.*`; do \
		${CP} $$f ${WRKSRC}/mlyacc/src/; \
	done
.else
	@${MKDIR} ${BOOT_WRKSRC}
	@${TAR} xf ${DISTDIR}/${BOOT_DIST} ${BOOT_EXTRACT} -C ${BOOT_WRKSRC}
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		"s|/usr/local/lib/mlton|${BOOT_WRKSRC}/lib/mlton|;s|/usr/local|${LOCALBASE}|" \
		${BOOT_WRKSRC}/bin/mlton
	@${REINPLACE_CMD} -e \
		"s|/usr/local|${LOCALBASE}|" \
		${WRKSRC}/runtime/Makefile \
		${WRKSRC}/runtime/bytecode/Makefile \
		${WRKSRC}/runtime/cenv.h \
		${WRKSRC}/bin/add-cross \
		${WRKSRC}/bin/add-local-cross \
		${WRKSRC}/bin/regression \
		${WRKSRC}/bin/mlton-script \
		${WRKSRC}/doc/guide/PortingMLton \
		${WRKSRC}/doc/guide/SelfCompiling \
		${WRKSRC}/doc/guide/Installation \
		${WRKSRC}/regression/parse.sml \
		${BOOT_WRKSRC}/lib/mlton/include/cenv.h
	@${RM} \
		${WRKSRC}/doc/guide/PortingMLton.bak \
		${WRKSRC}/doc/guide/SelfCompiling.bak \
		${WRKSRC}/doc/guide/Installation.bak

post-build:
.if defined(WITH_MINGW32)
	@${ECHO} Adding mingw32 target...
	${WRKSRC}/bin/add-local-cross mingw32 x86 mingw
.endif

post-install:
.for bin in mllex mlnlffigen mlprof mlton mlyacc
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PREFIX}/bin/${bin}	\
		${MAN1PREFIX}/man/man1/${bin}.1.gz
	${CHMOD} a+rx ${PREFIX}/bin/${bin}
.endfor
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/mlton
	${FIND} ${PREFIX}/lib/mlton -type f -exec ${CHMOD} a+r {} \;
	${FIND} ${PREFIX}/lib/mlton -type d -exec ${CHMOD} a+rx {} \;
	${CHMOD} a+x ${PREFIX}/lib/mlton/mlton-compile
	${CHMOD} a+x ${PREFIX}/lib/mlton/platform
.if !defined(NOPORTDOCS)
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	${FIND} ${DOCSDIR} -type f -exec ${CHMOD} a+r {} \;
	${FIND} ${DOCSDIR} -type d -exec ${CHMOD} a+rx {} \;
.endif

.include <bsd.port.post.mk>
