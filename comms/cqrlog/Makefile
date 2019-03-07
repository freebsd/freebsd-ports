# Created by: Stephen Hurd <shurd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cqrlog
PORTVERSION=	2.3.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	comms hamradio
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio logging application

LICENSE=	GPLv2

LIB_DEPENDS=	libhamlib.so:comms/hamlib

USES=		fpc lazarus:flavors shebangfix ssl:run dos2unix mysql
USE_GITHUB=	yes
GH_ACCOUNT=	ok2cqr

LLD_UNSAFE=	yes
SHEBANG_FILES=	tools/cqrlog-apparmor-fix \
		voice_keyer/voice_keyer.sh
USE_FPC=	cairo fcl-base chm fcl-db fcl-image fcl-json fcl-net fcl-web \
		fcl-registry rtl-extra fcl-xml mysql numlib openssl \
		pasjpeg regexpr x11

ALL_TARGET=	${PORTNAME}

MAKE_ENV+=	LAZBUILD_CMD="${LAZBUILD_CMD}" \
		LAZBUILD_ARGS="${LAZBUILD_ARGS}" \
		LCL_PLATFORM="${LCL_PLATFORM}" \
		LAZARUS_DIR="${LAZARUS_DIR}"

USE_XORG+=	x11
NO_LAZBUILD=	yes
LAZBUILD_ARGS=	-d --pcp=.
LAZARUS_NO_FLAVORS=qt5
INSTALLS_ICONS=	yes
DOS2UNIX_WRKSRC=${WRKSRC}/src/synapse/

gtk2_CONFLICTS_INSTALL=	${PORTNAME}-qt4
qt4_CONFLICTS_INSTALL=	${PORTNAME}-gtk2

post-extract:
	@${RM} -r ${WRKSRC}/src/lnet/lib/openssl.pas

post-patch:
	@${SED} -e s!%%LOCALBASE%%!${LOCALBASE}!g \
		-e s!%%MAKE_CMD%%!${MAKE_CMD}!g \
		-e s!%%LAZARUSDIR%%!${LAZARUS_DIR}!g \
		${FILESDIR}/environmentoptions.xml.in \
		> ${WRKSRC}/environmentoptions.xml
	${REINPLACE_CMD} -e s!%%LOCALBASE%%!${LOCALBASE}!g \
		${WRKSRC}/help/cwd.html ${WRKSRC}/help/h1.html \
		${WRKSRC}/src/cqrlog.lpi ${WRKSRC}/src/dData.pas \
		${WRKSRC}/src/dUtils.pas \
		${WRKSRC}/src/fLoTWExport.pas ${WRKSRC}/src/fLoTWExport.lfm \
		${WRKSRC}/src/fPreferences.pas ${WRKSRC}/src/fRotControl.pas \
		${WRKSRC}/src/fTRXControl.pas ${WRKSRC}/src/fGrayline.pas \
		${WRKSRC}/src/fPreferences.lfm ${WRKSRC}/src/fPreferences.pas
	${REINPLACE_CMD} -e s!%%DATADIR%%!${DATADIR}!g \
		${WRKSRC}/src/dData.pas ${WRKSRC}/src/fGrayline.pas
	${REINPLACE_CMD} -e s!Linux!FreeBSD!g \
		${WRKSRC}/src/fMain.lfm
	${REINPLACE_CMD} -e s!%%OPENSSLLIB%%!${OPENSSLLIB}!g \
		${WRKSRC}/src/synapse/ssl_openssl_lib.pas
	${RM} -r ${WRKSRC}/src/mysql

.include <bsd.port.mk>
