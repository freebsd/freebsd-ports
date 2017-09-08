# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	BitcoinArmory
PORTVERSION=	0.93.3
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	finance

MAINTAINER=	yuri@rawbw.com
COMMENT=	Desktop bitcoin management system

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/swig3.0:devel/swig30 \
		${LOCALBASE}/bin/pyrcc4:textproc/py-qt4-xml \
		${LOCALBASE}/bin/rsync:net/rsync
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=14.0.0:devel/py-twisted \
		${PYTHON_PKGNAMEPREFIX}psutil>1.2.1:sysutils/py-psutil \
		${LOCALBASE}/bin/bitcoind:net-p2p/bitcoin-daemon

USE_GITHUB=	yes
GH_ACCOUNT=	etotheipi

USES=		compiler:c++11-lang compiler:c++11-lib gmake pyqt:4 python:2 shebangfix
USE_PYQT=	core_run gui_run
SHEBANG_FILES=	ArmoryQt.py extras/extractKeysFromWallet.py
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CXXFLAGS+=	-DCRYPTOPP_DISABLE_ASM -fPIC
MAKE_ENV+=	PYTHON_CONFIG=${PYTHON_CMD}-config

MAKE_ARGS+=	CXXFLAGS="${CXXFLAGS}"
INSTALLS_ICONS=	yes
ICON_SIZES=	24x24 32x32 64x64

# When CRYPTOPP_DISABLE_ASM isn't needed any more, i386 amd64 should
# be made work through ASM code, and the other archs will still
# have CRYPTOPP_DISABLE_ASM

post-patch:
	@${REINPLACE_CMD} 's/python-config/$${PYTHON_CONFIG}/' ${WRKSRC}/cppForSwig/Makefile
	@${REINPLACE_CMD} 's/O_DSYNC/O_SYNC/' ${WRKSRC}/cppForSwig/mdb/mdb.c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/armory/_CppBlockUtils.so

	@${SED} -i.bak -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${STAGEDIR}/${LOCALBASE}/bin/armory && \
		${RM} ${STAGEDIR}/${LOCALBASE}/bin/armory.bak
	@${REINPLACE_CMD} 's|Exec=/usr/bin/armory|Exec=${LOCALBASE}/bin/armory|' ${STAGEDIR}/${LOCALBASE}/share/applications/*.desktop
.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/
	${MV} ${STAGEDIR}/${PREFIX}/share/armory/img/armory_icon_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/armoryicon.png
.endfor

.include <bsd.port.mk>
