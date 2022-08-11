PORTNAME=	hare
PORTVERSION=	g20220709
CATEGORIES=	devel
MASTER_SITES=	https://git.sr.ht/~sircmpwn/${PORTNAME}/archive/
PKGNAMESUFFIX=	-lang
DISTNAME=	bd1c1c4a
DIST_SUBDIR=	hare

MAINTAINER=	se@FreeBSD.org
COMMENT=	Hare language build system and standard library

LICENSE=	MPL20 GPLv3
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 # aarch64 riscv64

BUILD_DEPENDS=	harec:lang/harec \
		qbe:devel/qbe \
		scdoc:textproc/scdoc
RUN_DEPENDS=	harec:lang/harec

MAKE_ARGS=	DESTDIR=${STAGEDIR}

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTNAME}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
MAKE_ARGS+=	ARCH=x86_64
.endif

pre-build:
		${CP} ${FILESDIR}/config.mk ${WRKSRC}

post-stage:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
		${MV} ${STAGEDIR}${DATADIR}/src/hare/* ${STAGEDIR}${DATADIR}/
		${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/
		${INSTALL_DATA} ${WRKSRC}/docs/*.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.post.mk>
