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

BUILD_DEPENDS=	${LOCALBASE}/bin/mono:${PORTSDIR}/lang/mono
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	DOCS EXAMPLES

INSTALL_TARGET=	install destdir=${STAGEDIR} prefix=${PREFIX}
MAKE_JOBS_UNSAFE=	yes
USES=		gmake pkgconfig
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

DATADIR=	${PREFIX}/share/NAnt
DOCSDIR=	${PREFIX}/share/doc/NAnt

post-patch:
	@${REINPLACE_CMD} -e 's|lib/pkgconfig|libdata/pkgconfig|' ${WRKSRC}/NAnt.build

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} run-test

.include <bsd.port.mk>
