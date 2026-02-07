PORTNAME=	harec
DISTVERSION=	0.25.2
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	https://git.sr.ht/~sircmpwn/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

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
		PREFIX=${PREFIX} \
		VERSION=${DISTVERSION}

PLIST_FILES=	bin/harec
PORTDOCS=	*
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '\
	s|@$$(AS)|$$(AS)|g; \
	s|@$$(CC)|$$(CC)|g; \
	s|@$$(TDENV)|$$(TDENV)|g; \
	s|@$$(QBE)|$$(QBE)|g' \
	    ${PATCH_WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '\
	s|@$$(AS)|$$(AS)|g; \
	s|@$$(CC)|$$(CC)|g; \
	s|@$$(TDENV)|$$(TDENV)|g; \
	s|@$$(QBE)|$$(QBE)|g' \
	    ${PATCH_WRKSRC}/makefiles/tests.mk
	@${REINPLACE_CMD} -e '/printf/d' \
	    ${PATCH_WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/printf/d' \
	    ${PATCH_WRKSRC}/makefiles/tests.mk

do-configure:
	(cd ${WRKSRC} && ${CP} configs/freebsd.mk config.mk)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/.bin/harec ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
