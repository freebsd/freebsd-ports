# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qross
PORTVERSION=	0.3.1
CATEGORIES=	devel
MASTER_SITES=	GH GHC

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Qt-only fork of Kross, the KDE scripting framework

USES=		cmake tar:bzip2
USE_LDCONFIG=	yes
USE_QT4=	designer gui network xml qmake_build uic_build moc_build \
		rcc_build script testlib
USE_GITHUB=	yes
GH_ACCOUNT=	0xd34df00d
GH_PROJECT=	Qross

WRKSRC=		${WRKDIR}/0xd34df00d-Qross-82e1fd2/src

OPTIONS_DEFINE=	PYTHON
OPTIONS_DEFAULT=PYTHON

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
BUILD_DEPENDS=	sip:${PORTSDIR}/devel/py-sip
PLIST_SUB+=	PYTHON=""
.else
CMAKE_ARGS=	-DENABLE_PYTHON=OFF
PLIST_SUB+=	PYTHON="@comment "
.endif

post-extract:
	@${CP} ${FILESDIR}/CMakeLists.txt ${WRKSRC}

post-install:
.for lib in libqrossui libqrosscore qrossqts
	@${LN} -s ${lib}.so.0.1 ${STAGEDIR}${PREFIX}/lib/${lib}.so.1
.endfor

.include <bsd.port.mk>
