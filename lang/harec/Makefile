PORTNAME=	harec
PORTVERSION=	0.24.0
CATEGORIES=	lang
MASTER_SITES=	https://git.sr.ht/~sircmpwn/${PORTNAME}/archive/
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	harec

MAINTAINER=	se@FreeBSD.org
COMMENT=	Hare compiler written in C11
WWW=		https://harelang.org/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 # aarch64 riscv64

BUILD_DEPENDS=	as:devel/binutils \
		qbe:devel/qbe
RUN_DEPENDS=	as:devel/binutils \
		qbe:devel/qbe

USES=		compiler:c11

MAKE_ARGS=	ARCH=${ARCH:S/^amd64$/x86_64/} \
		DESTDIR=${STAGEDIR} \
		PREFIX=${PREFIX}

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTNAME}

PLIST_FILES=	bin/harec
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-build:
		cd ${WRKSRC} && ${CP} configs/freebsd.mk config.mk
		cd ${WRKSRC} && ${MAKE} ${MAKE_ARGS}

do-install:
		cd ${WRKSRC} && ${MAKE} ${MAKE_ARGS} install
		${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/bin/*
		${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${STAGEDIR}${DOCSDIR}

do-test:
		cd ${WRKSRC} && make ${MAKE_ARGS} check

.include <bsd.port.mk>
