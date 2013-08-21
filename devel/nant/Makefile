# Created by: Christopher Nehren <apeiron+ports@coitusmentis.info>
# $FreeBSD$

PORTNAME=	nant
PORTVERSION=	0.91
CATEGORIES=	devel
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	.NET build tool inspired by Ant

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	DOCS EXAMPLES

BROKEN=		fails to build

DATADIR=	${PREFIX}/share/NAnt
DOCSDIR=	${PREFIX}/share/doc/NAnt
INSTALL_TARGET=	install prefix=${PREFIX}
MAKE_ENV=	MONO_PATH=${WRKSRC}/lib TARGET=mono-4.0
MAKE_JOBS_UNSAFE=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|MCS=mcs|MCS=dmcs|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|lib/pkgconfig|libdata/pkgconfig|' ${WRKSRC}/NAnt.build
.if empty(PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '903,910 d' ${WRKSRC}/NAnt.build
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}/
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
