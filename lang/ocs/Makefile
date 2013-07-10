# Created by: Björn König <bkoenig@cs.tu-berlin.de>
# $FreeBSD$

PORTNAME=	ocs
PORTVERSION=	2.3k
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://user.cs.tu-berlin.de/~opal/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	bkoenig@cs.tu-berlin.de
COMMENT=	The OPAL Compilation System

BUILD_DEPENDS=	${LOCALBASE}/bin/gsed:${PORTSDIR}/textproc/gsed

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST=		${WRKDIR}/pkg-plist

# The Makefile of the source package doesn't have a 'build' target.
# It rather compiles and installs the software in a single step using
# an 'install' target. For this reason the port compiles/installs the
# software to a temporary directory at the 'do-build' stage and
# installs it manually at the 'do-install' stage.
ALL_TARGET=	install

USE_BZIP2=	yes
USES=		gmake
USE_TCL=	yes
USE_TK=		yes
USE_PERL5=	yes
HAS_CONFIGURE=	yes
USE_XORG=	xt
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	${OCS}/lib/freebsd${OSREL}-${ARCH}

NOT_FOR_ARCHS=	amd64 ia64 sparc64

CONFIGURE_ARGS=	--prefix="${WRKDIR}" \
		--disable-absolute-pathes \
		--disable-locallinks \
		--with-tcl-lib="-L${LOCALBASE}/lib -ltcl${TCL_VER:S/.//}" \
		--with-tcl-incl="-I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR} -I${LOCALBASE}/include" \
		--with-tk-lib="-ltk${TK_VER:S/.//}" \
		--with-tk-incl="-I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR} -I${LOCALBASE}/include"

MAN1=		ocs.1 oc.1 genmake.1

OCS_LINKS=	oasys ocs
OCS_INSTALL=	bin etc lib packages

# This is the place of the temporary installation.
OCS_TEMPDIR=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

# This is the target directory of the port installation.
OCS=		${PREFIX}/${PORTNAME}

.for f in ${OCS_LINKS}
PLIST_FILES+=	bin/$f
.endfor

post-patch:
.for f in src/om/scripts/oasys src/om/scripts/ocs
		@${REINPLACE_CMD} "s,OCS=.*$$,OCS=\"${OCS}\"," ${WRKSRC}/$f
.endfor
		@${REINPLACE_CMD} "s,\$$LIBS -ldl,\$$LIBS," ${WRKSRC}/configure

# The Makefile don't like an existing (temporary) installation directory.
# This won't hurt as long as we do a clean installation. But if you
# 'make build' several times because of an interrupted compilation then it
# is necessary to remove the directory to keep the make script satisfied.
pre-build:
		@${RM} -rf ${OCS_TEMPDIR}

pre-install:
		@${RM} -f ${PLIST}
		@${TOUCH} ${PLIST}
.for d in ${OCS_INSTALL}
		@${FIND} ${OCS_TEMPDIR}/$d -not -type d | ${SED} "s,${OCS_TEMPDIR},${PORTNAME}," >> ${PLIST}
		@${FIND} -d ${OCS_TEMPDIR}/$d -type d | ${SED} "s,${OCS_TEMPDIR},@dirrmtry ${PORTNAME}," >> ${PLIST}
.endfor
		@${ECHO} "@dirrmtry ${PORTNAME}" >> ${PLIST}
.if !defined(WITHOUT_EXAMPLES)
		@${FIND} ${OCS_TEMPDIR}/examples -not -type d | ${SED} "s,${OCS_TEMPDIR}/examples,${EXAMPLESDIR_REL}," >> ${PLIST}
		@${FIND} -d ${OCS_TEMPDIR}/examples -type d | ${SED} "s,${OCS_TEMPDIR}/examples,@dirrmtry ${EXAMPLESDIR_REL}," >> ${PLIST}
.endif

do-install:
		@${MKDIR} ${OCS}
.for d in ${OCS_INSTALL}
		@(cd ${OCS_TEMPDIR}; ${COPYTREE_BIN} $d ${OCS})
.endfor
.if !defined(WITHOUT_EXAMPLES)
		@(cd ${OCS_TEMPDIR}/examples; ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif
.for f in ${OCS_LINKS}
		@${LN} -s ${OCS}/bin/$f ${PREFIX}/bin/$f
.endfor
.for f in ${MAN1}
		@${INSTALL_MAN} ${OCS_TEMPDIR}/man/man1/$f ${MAN1PREFIX}/man/man1/
.endfor

.include <bsd.port.mk>
