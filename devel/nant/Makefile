# Created by: Christopher Nehren <apeiron+ports@coitusmentis.info>
# $FreeBSD$

PORTNAME=	nant
PORTVERSION=	0.92
CATEGORIES=	devel
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	.NET build tool inspired by Ant

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	DOCS EXAMPLES

INSTALL_TARGET=	install prefix=${PREFIX}
MAKE_JOBS_UNSAFE=	yes
USES=		gmake
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

DATADIR=	${PREFIX}/share/NAnt
DOCSDIR=	${PREFIX}/share/doc/NAnt

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|lib/pkgconfig|libdata/pkgconfig|' ${WRKSRC}/NAnt.build
.if !${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '851,858 d' ${WRKSRC}/NAnt.build
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}/
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${EXAMPLESDIR}/
.endif

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE} run-test

.include <bsd.port.mk>
