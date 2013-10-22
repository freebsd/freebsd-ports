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

LIB_DEPENDS=	boost_thread:${PORTSDIR}/devel/boost-libs

USE_QT4=	gui network xml moc_build qmake_build rcc_build uic_build
HAS_CONFIGURE=	yes
QMAKE_ARGS=	-recursive PREFIX=${PREFIX} \
		DEFAULT_PLUGIN_PATH="${PREFIX}/libexec/${PORTNAME}"

WRKSRC=		${WRKDIR}/debugger

MAN1=		edb.1
PORTDOCS=	*

ONLY_FOR_ARCHS=	i386 amd64

STRIP_FILES=	bin/${PORTNAME} libexec/${PORTNAME}/*.so

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800505
BROKEN=		doesn't build due to lack of memory map of ptrace
.endif

.include <bsd.port.options.mk>

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKE_ARGS} ${QMAKEFLAGS}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/edb.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/src/images/edb48-logo.png ${PREFIX}/share/pixmaps/edb.png
	${INSTALL_MAN} ${WRKSRC}/edb.1 ${MANPREFIX}/man/man1/edb.1
	${STRIP_CMD} ${STRIP_FILES:S,^,${PREFIX}/,}

.include <bsd.port.post.mk>
