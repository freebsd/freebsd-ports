# New ports collection makefile for:	mk-configure
# Date created:				16 September 2009
# Whom:					Mikolaj Golub <to.my.trociny@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mk-configure
PORTVERSION=	0.21.1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	to.my.trociny@gmail.com
COMMENT=	Lightweight, easy to use replacement for GNU autotools

BUILD_DEPENDS=	${BMAKE}:${PORTSDIR}/devel/bmake
RUN_DEPENDS:=	${BUILD_DEPENDS}

LICENSE=	BSD

BMAKE?=		${LOCALBASE}/bin/bmake
INSTALL_TARGET=	installdirs install

PORTDOCS=	README NEWS TODO COPYRIGHT FAQ presentation.pdf
PORTEXAMPLES=	*

MAN1=		mkc_check_funclib.1 mkc_check_header.1 mkc_check_sizeof.1 \
		mkc_check_decl.1 mkc_check_prog.1 mkc_check_custom.1 \
		mkcmake.1
MAN7=		mk-configure.7

.if !defined(NOPORTDOCS)
MAKE_ENV+=	EXTRAFILES="${PORTDOCS:C|.*\.pdf|doc/&|}"
.else
MAKE_ENV+=	EXTRAFILES=""
.endif

do-build:
	@${SETENV} ${MAKE_ENV} ${BMAKE} -C ${BUILD_WRKSRC} ${MAKE_FLAGS} ${MAKEFILE} \
		${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}

do-install:
	@${SETENV} ${MAKE_ENV} ${BMAKE} -C ${INSTALL_WRKSRC} ${MAKE_FLAGS} ${MAKEFILE} \
		${_MAKE_JOBS} ${MAKE_ARGS} ${INSTALL_TARGET}
.if !defined(NOPORTEXAMPLES)
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
