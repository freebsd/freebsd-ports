# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lockfree-malloc
PORTVERSION=	0.0.${DATE}
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	LOCAL/vg

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Scalable drop-in replacement for malloc/free

LICENSE=	LGPL3

DATE=		20120802
ONLY_FOR_ARCHS=	amd64
USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_GCC=	yes

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS
DOCS_DESC=	Install README

PLIST_FILES=	lib/liblite-malloc-shared.so \
		lib/liblite-malloc-static.a

MAKE_ARGS+=	CXX=${CXX}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PLIST_FILES+=	share/doc/${PORTNAME}/README
PLIST_DIRS+=	share/doc/${PORTNAME}
.endif

do-install:
.for i in shared.so static.a
	${INSTALL_LIB} ${WRKSRC}/liblite-malloc-${i} ${PREFIX}/lib/liblite-malloc-${i}
.endfor

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README ${DOCSDIR}
.endif

.include <bsd.port.mk>
