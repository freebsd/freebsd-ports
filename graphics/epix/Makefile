PORTNAME=	epix
DISTVERSION=	1.2.22
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://mathcs.holycross.edu/~ahwang/${PORTNAME}/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Creates math plots and line figures using easy-to-learn syntax
WWW=		https://mathcs.holycross.edu/~ahwang/epix/ePiX.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash

USES=		gmake makeinfo tar:bzip2 tex
USE_TEX=	dvipsk:build latex
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-bash=${LOCALBASE}/bin/bash \
		--with-runtime=${CXX}

INFO=		epix

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		'/usepackage/s|\(pstricks\),\(xcolor\)|\1,tikz,\2|' \
		${WRKSRC}/doc/manual.tex

.include <bsd.port.mk>
