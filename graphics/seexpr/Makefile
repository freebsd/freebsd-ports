# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	seexpr
DISTVERSION=	1.0.1.2015.08.29
CATEGORIES=	graphics math

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Embeddable expression evaluation language

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/share/py-sip/QtGui/QtGuimod.sip:${PORTSDIR}/x11-toolkits/py-qt4-gui

USE_GITHUB=	yes
GH_ACCOUNT=	wdas
GH_TAGNAME=	36ffb818b8

USES=		bison cmake compiler:c++0x python
USE_QT4=	moc_build qmake_build rcc_build uic_build gui opengl

WRKSRC=		${WRKDIR}/SeExpr-${GH_TAGNAME_EXTRACT}

CXXFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.pre.mk>

# base flex(1) v2.5.4 is not sufficient
.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex
.endif

post-patch:
	@${REINPLACE_CMD} -e '/<alloca\.h>/d' ${WRKSRC}/src/SeExpr/SePlatform.h
	@${REINPLACE_CMD} -e 's, "dl",,' ${WRKSRC}/src/SeExpr/CMakeLists.txt
	@${REINPLACE_CMD} -e '/tests/d' ${WRKSRC}/CMakeLists.txt
.if ${OSVERSION} < 1000033
	@${REINPLACE_CMD} -e '/COMMAND/s,flex,${LOCALBASE}/bin/&,' \
		${WRKSRC}/src/build/macros.cmake
.endif

.include <bsd.port.post.mk>
