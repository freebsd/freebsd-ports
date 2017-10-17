# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	cd-hit
PORTVERSION=	4.6.6
PORTREVISION=	2
DISTVERSIONPREFIX=	V
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Clustering and comparing protein or nucleotide sequences

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	weizhongli
GH_PROJECT=	cdhit

USES=		compiler:openmp gmake shebangfix
SHEBANG_FILES=	${WRKSRC}/*.pl

MAKE_FLAGS=	openmp=yes

post-patch:
	@${REINPLACE_CMD} \
		-e 's|g++|${CXX}|g' \
		-e 's|\$$(PREFIX)|$${DESTDIR}$${PREFIX}/bin|g' \
		${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} \
		-e 's|/bin/bash|${LOCALBASE}/bin/bash|g' \
		${WRKSRC}/*.pl

post-install:
	@cd ${STAGEDIR}${PREFIX}/bin && \
		${STRIP_CMD} cd-hit cd-hit-2d cd-hit-454 \
		cd-hit-div cd-hit-est cd-hit-est-2d

.include <bsd.port.mk>
