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
PORTVERSION=	20040227
CATEGORIES=	lang
MASTER_SITES=	http://www.mlton.org/download/	\
		http://www.mlton.org/experimental/
DISTFILES=	${BOOT_DIST} ${SRC_DIST}
EXTRACT_ONLY=	${SRC_DIST}

MAINTAINER=	MLton@mlton.org
COMMENT=	An optimizing Standard ML compiler

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash2		\
		hevea:${PORTSDIR}/textproc/hevea 	\
		latex:${PORTSDIR}/print/teTeX
LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2

SRC_DIST=	${DISTNAME}-1.freebsd.src.tgz
BOOT_DIST=	${PORTNAME}-${BOOT_VER}-1.${MACHINE_ARCH}-freebsd.${BOOT_SUF}

ONLY_FOR_ARCHS=	i386

MAN1=		mllex.1 mlprof.1 mlton.1 mlyacc.1
MANCOMPRESSED=	yes

BOOT_WRKSRC=	${WRKDIR}/mlton-bootstrap

USE_GETTEXT=	yes
USE_REINPLACE=	yes
ALL_TARGET=	all
USE_GMAKE=	yes
MAKE_ARGS=	DESTDIR='' \
		PATH=${WRKSRC}/build/bin:${BOOT_WRKSRC}/bin:${PATH} \
		PREFIX=${PREFIX}

PORTDIR=	usr/ports/lang/mlton

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BOOT_EXTRACT=	--gzip
BOOT_SUF=	tgz
BOOT_VER=	20040429
.else
BOOT_EXTRACT=	--bzip
BOOT_SUF=	tbz
BOOT_VER=	20040623
.endif

post-extract:
	@${MKDIR} ${BOOT_WRKSRC}
	@${TAR} xf ${DISTDIR}/${BOOT_DIST} ${BOOT_EXTRACT} -C ${BOOT_WRKSRC}
	@${REINPLACE_CMD} -e \
		"s|lib=\'${LOCALBASE}/|lib=\'${BOOT_WRKSRC}/|" \
	${BOOT_WRKSRC}/bin/mlton

post-install:
.for bin in mllex mlprof mlton mlyacc
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PREFIX}/bin/${bin}	\
		${MAN1PREFIX}/man/man1/${bin}.1.gz
.endfor
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/mlton	${DOCSDIR}

# Stuff below this line is for maintainer use only.

.if defined(MAINTAINER_MODE)
.PHONY: build-package
build-package:
	${MAKE} makesum build
	${MAKE} pkg-plist
	portlint .
	${MAKE} deinstall
	${MAKE} install
	${MAKE} package
	${MAKE} deinstall
	pkg_add ${PORTNAME}-${PORTVERSION}.tbz
	${MAKE} deinstall
	${MAKE} reinstall
	${MAKE} package
	${CP} ${PORTNAME}-${PORTVERSION}.tbz	\
		${DISTDIR}/${PORTNAME}-${PORTVERSION}-1.i386-freebsd.tbz
	${TAR} -cpf - Makefile distinfo pkg-descr pkg-plist | \
		( ${MKDIR} ${PORTDIR} && cd ${PORTDIR} && ${TAR} -xpf - )
	shar `find ${PORTDIR}` >/tmp/mlton-${PORTVERSION}-portdir.shar

TMP_PLIST=	tmp-pkg-plist
PLIST=		${.CURDIR}/pkg-plist

pkg-plist:
	cd ${WRKSRC} && ${GMAKE} install
	cd ${WRKSRC}/install/usr && \
		${FIND} -d * \! -type d | ${GREP} -v man/man | \
		${SORT} >${PLIST}
	cd ${WRKSRC}/install/usr && \
		${FIND} -d * -type d | ${GREP} mlton | \
			${SED} -e 's/^/@dirrm /' >>${PLIST}
	${SED} -e 's;@dirrm share/doc/mlton;%%PORTDOCS%%@dirrm %%DOCSDIR%%;' \
		<${PLIST} >${TMP_PLIST}
	${SED} -e 's;share/doc/mlton;%%PORTDOCS%%%%DOCSDIR%%;'	\
		<${TMP_PLIST} >${PLIST}
	${RM} ${TMP_PLIST}

.endif # MAINTAINER_MODE

.include <bsd.port.post.mk>
