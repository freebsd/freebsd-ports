PORTNAME=	mdb
PORTVERSION=	20250623
CATEGORIES=	devel

MAINTAINER=	jhb@FreeBSD.org
COMMENT=	Solaris Modular Debugger
WWW=		https://docs.oracle.com/cd/E19683-01/806-6545/index.html

LICENSE=	CDDL

USES=		compiler uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	bsdjhb
GH_PROJECT=	illumos-gate
GH_TAGNAME=	612cd42

ONLY_FOR_ARCHS=	amd64

MAKE_ARGS=	WITH_CTF=yes
MAKE_ARGS+=	BINDIR=${PREFIX}/bin
MAKE_ARGS+=	LIBDIR=${PREFIX}/lib
MAKE_ARGS+=	FREEBSD_SRC_DIR=${SRC_BASE}
MAKE_ARGS+=	STRIP=
WRKSRC_SUBDIR=	freebsd/cddl/usr.bin/mdb
CFLAGS+=	-DMDB_PREFIX=\\\"${PREFIX}\\\" -g

.include <bsd.port.pre.mk>

.if !exists(${SRC_BASE}/cddl/compat) || !exists(${SRC_BASE}/sys/cddl/compat)
IGNORE=		requires full source tree with CDDL sources
.endif

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/mdb/kvm/${MACHINE_ARCH}

.include <bsd.port.post.mk>
