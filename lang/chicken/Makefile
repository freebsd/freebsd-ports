# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	chicken
PORTVERSION=	4.8.0.1
CATEGORIES=	lang scheme
MASTER_SITES=	http://code.call-cc.org/releases/4.8.0/

MAINTAINER=	vmagerya@gmail.com
COMMENT=	A Scheme-to-C compiler

MAKE_JOBS_SAFE=	yes

USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
USE_LDCONFIG=	yes
MAKE_ARGS+=	PLATFORM=bsd PREFIX=${PREFIX} \
		TOPMANDIR=${PREFIX}/man ARCH=${NEW_ARCH} \
		C_COMPILER="${CC}" \
		CXX_COMPILER="${CXX}" \
		LIBRARIAN="${AR}" \
		DOCDIR="${DOCSDIR}" \
		C_COMPILER_OPTIMIZATION_OPTIONS="${CFLAGS}"

NEW_ARCH=	${ARCH:S/i386/x86/:S/amd64/x86-64/}

MAN1=		chicken.1 chicken-bug.1 chicken-install.1 chicken-profile.1 \
		chicken-status.1 chicken-uninstall.1 csc.1 csi.1

.include <bsd.port.options.mk>

.if ${ARCH} != "amd64" && ${ARCH} != "i386" && ${ARCH} != "sparc64"
MAKE_ARGS+=	HACKED_APPLY=
.endif

post-patch:
.if empty(PORT_OPTIONS:MDOCS)
	${REINPLACE_CMD} -e '/$$(DESTDIR)$$(IDOCDIR)/d' ${WRKSRC}/rules.make
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}
.endif
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

# This only works *after* chicken is installed.
regression-test: build
	(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} \
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
