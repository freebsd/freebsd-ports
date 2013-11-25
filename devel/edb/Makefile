# $FreeBSD$

PORTNAME=	edb
PORTVERSION=	0.9.18
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://codef00.com/projects/
DISTNAME=	debugger-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	itechbear@gmail.com
COMMENT=	Cross-platform x86/x86-64 debugger based on Qt 4

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs

USES=		qmake
USE_QT4=	gui network xml moc_build rcc_build uic_build
QMAKE_ARGS=	DEFAULT_PLUGIN_PATH="${PREFIX}/libexec/${PORTNAME}"

WRKSRC=		${WRKDIR}/debugger

PORTDOCS=	*

ONLY_FOR_ARCHS=	i386 amd64

STRIP_FILES=	bin/${PORTNAME} libexec/${PORTNAME}/*.so

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.endif
	${INSTALL_DATA} ${WRKSRC}/edb.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/src/images/edb48-logo.png ${STAGEDIR}${PREFIX}/share/pixmaps/edb.png
	${INSTALL_MAN} ${WRKSRC}/edb.1 ${STAGEDIR}${MANPREFIX}/man/man1/edb.1
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	${STRIP_CMD} ${STRIP_FILES:S,^,${STAGEDIR}${PREFIX}/,}

.include <bsd.port.mk>
