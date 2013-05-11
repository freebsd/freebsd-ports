# ex:ts=8
# Ports collection makefile for:	epix
# Date created:			Sep 5, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	epix
PORTVERSION=	1.2.10
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://mathcs.holycross.edu/~ahwang/epix/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Creates math plots and line figures using easy-to-learn syntax

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	latex-pgf>=0:${PORTSDIR}/print/latex-pgf \
		bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_BZIP2=	yes
USE_TEX=	latex dvipsk:build
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-bash=${LOCALBASE}/bin/bash \
		--with-runtime=${CXX}
MAKE_JOBS_SAFE=	yes

MAN1=		elaps.1 epix.1 flix.1 laps.1
INFO=		epix

post-patch:
	@${REINPLACE_CMD} -e '/^install-data-am:/s|install-data-local||' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^install-data-am:/s|install-docDATA||' \
		${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e '/usepackage/s|pstricks,xcolor|pstricks,tikz,xcolor|' \
		${WRKSRC}/doc/manual.tex
	@${REINPLACE_CMD} -e '/^install-data-am:/s|install-docDATA||' \
		${WRKSRC}/samples/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} install-data-local)
	@(cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} install-docDATA)
	@(cd ${WRKSRC}/samples && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} install-docDATA)
.endif

.include <bsd.port.mk>
