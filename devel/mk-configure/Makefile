# Created by: Mikolaj Golub <to.my.trociny@gmail.com>
# $FreeBSD$

PORTNAME=	mk-configure
PORTVERSION=	0.24.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Lightweight, easy to use replacement for GNU autotools

LICENSE=	BSD

BUILD_DEPENDS=	${BMAKE}:${PORTSDIR}/devel/bmake
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		bmkdep:${PORTSDIR}/devel/bmkdep

BMAKE?=		${LOCALBASE}/bin/bmake
INSTALL_TARGET=	installdirs install

PORTDOCS=	README NEWS TODO COPYRIGHT FAQ presentation.pdf
PORTEXAMPLES=	*

.if !defined(NOPORTDOCS)
MAKE_ENV+=	EXTRAFILES="${PORTDOCS:C|.*\.pdf|doc/&|}"
.else
MAKE_ENV+=	EXTRAFILES=""
.endif

post-patch:
	@${ECHO_CMD} "MKDEP ?= bmkdep" >> ${WRKSRC}/sys.mk

do-build:
	@${SETENV} ${MAKE_ENV} ${BMAKE} -C ${BUILD_WRKSRC} ${MAKE_FLAGS} ${MAKEFILE} \
		${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}

do-install:
	@${SETENV} ${MAKE_ENV} ${BMAKE} -C ${INSTALL_WRKSRC} ${MAKE_FLAGS} ${MAKEFILE} \
		${_MAKE_JOBS} ${MAKE_ARGS} ${INSTALL_TARGET}
.if !defined(NOPORTEXAMPLES)
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
