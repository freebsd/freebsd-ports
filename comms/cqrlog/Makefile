# Created by: Stephen Hurd <shurd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cqrlog
PORTVERSION=	2.4.0
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	comms hamradio
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio logging application

LICENSE=	GPLv2

LIB_DEPENDS=	libhamlib.so:comms/hamlib

USES=		fpc gnome lazarus:flavors shebangfix ssl:run dos2unix \
		mysql:server xorg

USE_GNOME+=	cairo
USE_XORG=	x11
USE_GITHUB=	yes
GH_ACCOUNT=	ok2cqr

SHEBANG_FILES=	tools/cqrlog-apparmor-fix \
		voice_keyer/voice_keyer.sh
USE_FPC=	cairo fcl-base chm fcl-db fcl-image fcl-json fcl-net fcl-web \
		fcl-registry rtl-extra fcl-xml mysql numlib opengl openssl \
		pasjpeg regexpr x11

ALL_TARGET=	${PORTNAME}

MAKE_ENV+=	LAZBUILD_CMD="${LAZBUILD_CMD}" \
		LAZBUILD_ARGS="${LAZBUILD_ARGS}" \
		LCL_PLATFORM="${LCL_PLATFORM}" \
		LAZARUS_DIR="${LAZARUS_DIR}"

NO_LAZBUILD=	yes
LAZBUILD_ARGS=	-d --pcp=.
INSTALLS_ICONS=	yes
DOS2UNIX_WRKSRC=${WRKSRC}/src/synapse/

gtk2_CONFLICTS_INSTALL=	${PORTNAME}-qt5
qt5_CONFLICTS_INSTALL=	${PORTNAME}-gtk2

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
		${WRKSRC}/src/fMain.lfm ${WRKSRC}/src/fNewQSO.lfm \
		${WRKSRC}/src/dUtils.pas
	${REINPLACE_CMD} -e s!%%OPENSSLLIB%%!${OPENSSLLIB}!g \
		${WRKSRC}/src/synapse/ssl_openssl_lib.pas
	${RM} -r ${WRKSRC}/src/mysql

.include <bsd.port.mk>
