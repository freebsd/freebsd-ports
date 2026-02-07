PORTNAME=		cd-hit
DISTVERSIONPREFIX=	V
DISTVERSION=		4.8.1
PORTREVISION=		3
CATEGORIES=		biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Clustering and comparing protein or nucleotide sequences
WWW=		http://weizhong-lab.ucsd.edu/cd-hit/

LICENSE=	GPLv2

USES=		gmake shebangfix
USE_GITHUB=	yes

GH_ACCOUNT=	weizhongli
GH_PROJECT=	cdhit
SHEBANG_FILES=	${WRKSRC}/*.pl

.if exists(/usr/include/omp.h)
MAKE_FLAGS=	openmp=yes
.else
MAKE_FLAGS=	openmp=no
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|/bin/bash|${LOCALBASE}/bin/bash|g' \
		${WRKSRC}/cd-hit-2d-para.pl \
		${WRKSRC}/cd-hit-para.pl

post-install:
	@cd ${STAGEDIR}${PREFIX}/bin && \
		${STRIP_CMD} cd-hit cd-hit-2d cd-hit-454 \
		cd-hit-div cd-hit-est cd-hit-est-2d

.include <bsd.port.mk>
