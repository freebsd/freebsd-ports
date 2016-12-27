# Created by: Christopher Nehren <apeiron+ports@coitusmentis.info>
# $FreeBSD$

PORTNAME=	nant
PORTVERSION=	0.92
DISTVERSIONSUFFIX=	-src
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	.NET build tool inspired by Ant

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

OPTIONS_DEFINE=	DOCS EXAMPLES

INSTALL_TARGET=	install destdir=${STAGEDIR} prefix=${PREFIX}
MAKE_ARGS=	MCS=mcs MONO='mono --runtime=v4.0' TARGET=mono-4.0
MAKE_JOBS_UNSAFE=	yes
TEST_TARGET=	run-test
USES=		gmake mono pkgconfig
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

DATADIR=	${PREFIX}/share/NAnt
DOCSDIR=	${PREFIX}/share/doc/NAnt
EXAMPLESDIR=	${PREFIX}/share/examples/NAnt

post-patch:
	@${REINPLACE_CMD} -e 's|lib/pkgconfig|libdata/pkgconfig|' ${WRKSRC}/NAnt.build
	@${REINPLACE_CMD} -e 's|lib/mono/4.0|lib/mono/4.0-api|' \
		${WRKSRC}/src/NAnt.Console/App.config \
		${WRKSRC}/tests/NAnt.Core/Framework.config

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
