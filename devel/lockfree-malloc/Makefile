# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lockfree-malloc
PORTVERSION=	0.0.${DATE}
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	LOCAL/vg

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Scalable drop-in replacement for malloc/free

LICENSE=	LGPL3

DATE=		20120802
ONLY_FOR_ARCHS=	amd64
USE_LDCONFIG=	yes
USES=		tar:bzip2
USE_GCC=	yes

OPTIONS_DEFINE=	DOCS
DOCS_DESC=	Install README

PLIST_FILES=	lib/liblite-malloc-shared.so \
		lib/liblite-malloc-static.a

MAKE_ARGS+=	CXX=${CXX}

DOCS_PLIST_FILES=	share/doc/${PORTNAME}/README

do-install:
.for i in shared.so static.a
	${INSTALL_LIB} ${WRKSRC}/liblite-malloc-${i} ${STAGEDIR}${PREFIX}/lib/liblite-malloc-${i}
.endfor

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
