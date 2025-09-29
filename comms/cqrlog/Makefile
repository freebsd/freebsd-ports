PORTNAME=	cqrlog
PORTVERSION=	2.5.2
PORTREVISION=	16
DISTVERSIONPREFIX=	v
CATEGORIES=	comms hamradio
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio logging application
WWW=		https://www.cqrlog.com/

LICENSE=	GPLv2

LIB_DEPENDS=	libhamlib.so:comms/hamlib

ONLY_FOR_ARCHS=	amd64 i386

USES=		fpc gnome lazarus:flavors shebangfix ssl:run dos2unix \
		mysql:server xorg

USE_GNOME+=	cairo
USE_XORG=	x11
USE_GITHUB=	yes
GH_ACCOUNT=	ok2cqr

SHEBANG_FILES=	tools/cqrlog-apparmor-fix \
		voice_keyer/voice_keyer.sh

ALL_TARGET=	${PORTNAME}

MAKE_ENV+=	LAZBUILD_CMD="${LAZBUILD_CMD}" \
		LAZBUILD_ARGS="${LAZBUILD_ARGS}" \
		LCL_PLATFORM="${LCL_PLATFORM}" \
		LAZARUS_DIR="${LAZARUS_DIR}"

NO_LAZBUILD=	yes
LAZBUILD_ARGS=	-d --pcp=.
DOS2UNIX_WRKSRC=${WRKSRC}/src/synapse/

gtk2_CONFLICTS_INSTALL=	${PORTNAME}-qt5 ${PORTNAME}-qt6
qt5_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt6
qt6_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt5

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
		${WRKSRC}/src/fTRXControl.pas ${WRKSRC}/src/fPreferences.lfm
	${REINPLACE_CMD} -e s!%%DATADIR%%!${DATADIR}!g \
		${WRKSRC}/src/dData.pas ${WRKSRC}/src/fGrayline.pas
	${REINPLACE_CMD} -e 's|ifdef LCLQT5|if defined\(LCLQT5\) or defined\(LCLQT6\)|g' \
		${WRKSRC}/src/lnet/lib/lclnet.pas
	${REINPLACE_CMD} -e 's|unixutil|Unix|g' -e 's|UnixUtil|Unix|g' \
		${WRKSRC}/src/lnet/lib/lcommon.pp

post-build:
	@${RM} ${WRKSRC}/help/cwd.html.*
	@${RM} ${WRKSRC}/help/h1.html.*

.include <bsd.port.mk>
