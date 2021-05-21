# Created by: Yuri Victorovich <yuri@rawbw.com>

PORTNAME=	BitcoinArmory
DISTVERSIONPREFIX=	v
DISTVERSION=	0.96.5.20210412
CATEGORIES=	finance

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Desktop bitcoin management system

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		fails to compile: c++: language not recognized: 'ar'
BROKEN_armv6=		fails to compile: c++: language not recognized: 'ar'
BROKEN_armv7=		fails to compile: c++: language not recognized: 'ar'

BUILD_DEPENDS=	${LOCALBASE}/bin/swig:devel/swig \
		${LOCALBASE}/bin/pyrcc5-${PYTHON_VER}:textproc/py-qt5-xml@${PY_FLAVOR} \
		${LOCALBASE}/bin/rsync:net/rsync
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=14.0.0:devel/py-twisted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>1.2.1:sysutils/py-psutil@${PY_FLAVOR} \
		${LOCALBASE}/bin/bitcoind:net-p2p/bitcoin-daemon

USES=		autoreconf compiler:c++11-lang compiler:c++11-lib gmake gnome localbase pyqt:5 pkgconfig python shebangfix ssl
USE_PYQT=	core_run gui_run

USE_GITHUB=	yes
GH_ACCOUNT=	goatpig
GH_TAGNAME=	443c918
GH_TUPLE=	weidai11:cryptopp:f375910:cryptopp/cppForSwig/cryptopp

SHEBANG_FILES=	ArmoryQt.py extras/extractKeysFromWallet.py

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SSL_CFLAGS=-I${OPENSSLINC} SSL_LIBDIR=${OPENSSLDIR} SSL_LIBS="-lssl" CRYPTO_CFLAGS=-I${OPENSSLINC} CRYPTO_LIBDIR=${OPENSSLDIR} CRYPTO_LIBS="-lcrypto"

#CFLAGS+=	-D_SEM_SEMUN_UNDEFINED
CXXFLAGS+=	-DCRYPTOPP_DISABLE_ASM -fPIC
MAKE_ENV+=	PYTHON_CONFIG=${PYTHON_CMD}-config
BINARY_ALIAS=	pyrcc5=pyrcc5-${PYTHON_VER}

MAKE_ARGS+=	CXXFLAGS="${CXXFLAGS}"
INSTALLS_ICONS=	yes
ICON_SIZES=	24x24 32x32 64x64

# When CRYPTOPP_DISABLE_ASM isn't needed any more, i386 amd64 should
# be made work through ASM code, and the other archs will still
# have CRYPTOPP_DISABLE_ASM

xpost-patch:
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
