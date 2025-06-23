PORTNAME=	hare
DISTVERSION=	0.25.2
CATEGORIES=	devel
MASTER_SITES=	https://git.sr.ht/~sircmpwn/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/
PKGNAMESUFFIX=	-lang

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
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '\
	s|@$$(AS)|$$(AS)|g; \
	s|@$$(LD)|$$(LD)|g; \
	s|@$$(QBE)|$$(QBE)|g' \
	    ${PATCH_WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/printf/d' \
	    ${PATCH_WRKSRC}/Makefile

do-configure:
	(cd ${WRKSRC} && ${CP} configs/freebsd.mk config.mk)

post-install:
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/bin/*
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
