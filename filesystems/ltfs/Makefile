PORTNAME=	ltfs
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.8.1
DISTVERSIONSUFFIX=	-10519
CATEGORIES=	filesystems sysutils

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Reference implementation of LTFS for stand-alone tape drive
WWW=		https://github.com/LinearTapeFileSystem/ltfs

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libicudata.so:devel/icu \
		libuuid.so:misc/libuuid

USES=		autoreconf compiler:c11 fuse gnome libtool:build pkgconfig \
		python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	LinearTapeFileSystem
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

SHEBANG_FILES=	src/utils/ltfs_ordered_copy

GNU_CONFIGURE=			yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

CONFIGURE_ARGS+=	--enable-icu-6x

#INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DEBUG SNMP
OPTIONS_SUB=	yes

DEBUG_DESC=	Build without optimization and extended debug flags
SNMP_DESC=	SNMP trap support

DEBUG_CONFIGURE_ON=	--enable-debug
DEBUG_CONFIGURE_OFF=	--enable-fast

SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
SNMP_USES=		perl5
SNMP_CONFIGURE_ENABLE=	snmp

post-install:
	@${RM} ${STAGEDIR}${DATADIR}/ltfs
	@${RMDIR} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
