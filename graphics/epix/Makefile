# Created by: ijliao
# $FreeBSD$

PORTNAME=	epix
PORTVERSION=	1.2.13
CATEGORIES=	graphics
MASTER_SITES=	http://mathcs.holycross.edu/~ahwang/epix/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Creates math plots and line figures using easy-to-learn syntax

LICENSE=	GPLv2 # (or later)

BUILD_DEPENDS=	latex-pgf>=0:${PORTSDIR}/print/latex-pgf \
		bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

OPTIONS_DEFINE=	DOCS

USE_BZIP2=	yes
USES=		gmake
USE_TEX=	latex dvipsk:build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-bash=${LOCALBASE}/bin/bash \
		--with-runtime=${CXX}

INFO=		epix

post-patch:
	@${REINPLACE_CMD} -e '/usepackage/s|pstricks,xcolor|pstricks,tikz,xcolor|' \
		${WRKSRC}/doc/manual.tex

.include <bsd.port.mk>
