PORTNAME=	hare
PORTVERSION=	0.24.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://git.sr.ht/~sircmpwn/${PORTNAME}/archive/
PKGNAMESUFFIX=	-lang
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	hare

MAINTAINER=	se@FreeBSD.org
COMMENT=	Hare language build system and standard library
WWW=		https://harelang.org/

LICENSE=	GPLv3 MPL20
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 # aarch64 riscv64

BUILD_DEPENDS=	harec:lang/harec \
		qbe:devel/qbe \
		scdoc:textproc/scdoc
RUN_DEPENDS=	harec:lang/harec

MAKE_ARGS=	ARCH=${ARCH:S/^amd64$/x86_64/} \
		DESTDIR=${STAGEDIR} \
		HARECACHE=${WRKDIR}/.cache/hare \
		PREFIX=${PREFIX}

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTNAME}

OPTIONS_DEFINE=	DOCS

do-build:
		cd ${WRKSRC} && ${CP} configs/freebsd.mk config.mk
		cd ${WRKSRC} && ${MAKE} ${MAKE_ARGS}

do-install:
		cd ${WRKSRC} && ${MAKE} ${MAKE_ARGS} install
		${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/bin/*
		${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/docs/*.md ${STAGEDIR}${DOCSDIR}/

do-test:
		cd ${WRKSRC} && ${MAKE} ${MAKE_ARGS} check

.include <bsd.port.mk>
