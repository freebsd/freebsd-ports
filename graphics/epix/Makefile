# Created by: ijliao
# $FreeBSD$

PORTNAME=	epix
PORTVERSION=	1.2.16
CATEGORIES=	graphics
MASTER_SITES=	http://mathcs.holycross.edu/~ahwang/epix/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Creates math plots and line figures using easy-to-learn syntax

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash

USES=		gmake makeinfo tar:bzip2
USE_TEX=	latex dvipsk:build texmf:build
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
