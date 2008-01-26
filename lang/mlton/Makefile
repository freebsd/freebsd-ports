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
CATEGORIES=	lang
MASTER_SITES=	http://mlton.org/pages/Download/attachments/ \
		http://mlton.org/pages/Experimental/attachments/
DISTFILES=	${BOOT_DIST} ${SRC_DIST}
EXTRACT_ONLY=	${SRC_DIST}

# Other maintainer is Geoffrey Mainland (mainland@apeiron.net)
MAINTAINER=	jesper.louis.andersen@gmail.com
COMMENT=	An optimizing Standard ML compiler

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	gsed:${PORTSDIR}/textproc/gsed \
		htmldoc:${PORTSDIR}/textproc/htmldoc \
		latex:${PORTSDIR}/print/teTeX
.endif
LIB_DEPENDS=	gmp.7:${PORTSDIR}/math/libgmp4
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

SRC_DIST=	${DISTNAME}-1.src.tgz
BOOT_DIST=	${PORTNAME}-${BOOT_VER}-1-0.${MACHINE_ARCH}-freebsd.${BOOT_SUF}

ONLY_FOR_ARCHS=	i386

MAN1=		mllex.1 mlprof.1 mlton.1 mlyacc.1 mlnlffigen.1
MANCOMPRESSED=	yes

BOOT_WRKSRC=	${WRKDIR}/mlton-bootstrap

ALL_TARGET=	all
USE_GMAKE=	yes
MAKE_ARGS=	DESTDIR='' \
		PATH=${WRKSRC}/build/bin:${BOOT_WRKSRC}/bin:${PATH} \
		PREFIX=${PREFIX}

.if defined(NOPORTDOCS)
INSTALL_TARGET=	install-no-docs
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
MLTON_ARCH=	"x86"
.endif

.if ${OSVERSION} < 700000
IGNORE=		cannot bootstrap on FreeBSD < 7.0
.endif

BOOT_EXTRACT=	--bzip2
BOOT_SUF=	tbz
BOOT_VER=	20070826

post-extract:
	@${MKDIR} ${BOOT_WRKSRC}
	@${TAR} xf ${DISTDIR}/${BOOT_DIST} ${BOOT_EXTRACT} -C ${BOOT_WRKSRC}
	@${REINPLACE_CMD} -e \
		"s|lib=\'${LOCALBASE}/|lib=\'${BOOT_WRKSRC}/|" \
		${BOOT_WRKSRC}/bin/mlton

post-patch:
	@${REINPLACE_CMD} -e \
		"s|FLAGS += -I/usr/local/include|FLAGS += -I${LOCALBASE}/include|" \
		${WRKSRC}/runtime/Makefile
	@${REINPLACE_CMD} -e \
		"s|CFLAGS += -I/usr/local/include|CFLAGS += -I${LOCALBASE}/include|" \
		${WRKSRC}/runtime/bytecode/Makefile

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
