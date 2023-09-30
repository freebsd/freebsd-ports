PORTNAME=	hare
PORTVERSION=	g20230719
CATEGORIES=	devel
MASTER_SITES=	https://git.sr.ht/~sircmpwn/${PORTNAME}/archive/
PKGNAMESUFFIX=	-lang
DISTNAME=	0919412b
DIST_SUBDIR=	hare

MAINTAINER=	se@FreeBSD.org
COMMENT=	Hare language build system and standard library
WWW=		https://harelang.org/

LICENSE=	MPL20 GPLv3
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 # aarch64 riscv64

BUILD_DEPENDS=	harec:lang/harec \
		qbe:devel/qbe \
		scdoc:textproc/scdoc
RUN_DEPENDS=	harec:lang/harec

MAKE_ARGS=	ARCH=${ARCH:S/^amd64$/x86_64/} PREFIX=${PREFIX}

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTNAME}

OPTIONS_DEFINE=	DOCS

do-build:
		${CP} ${WRKSRC}/config.example.mk ${WRKSRC}/config.mk
		cd ${WRKSRC} && ${MAKE} ${MAKE_ARGS}

post-stage:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
		${MV} ${STAGEDIR}${DATADIR}/src/hare/* ${STAGEDIR}${DATADIR}/
		${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/
		${INSTALL_DATA} ${WRKSRC}/docs/*.md ${STAGEDIR}${DOCSDIR}/

do-test:
		cd ${WRKSRC} && ${MAKE} ${MAKE_ARGS} check

.include <bsd.port.mk>
