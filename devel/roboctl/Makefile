PORTNAME=	roboctl
DISTVERSION=	0.3.9-4
DISTVERSIONSUFFIX=	-gcae3172
CATEGORIES=	devel

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	API and tools for communicating with Lego and Vex robots
WWW=		https://github.com/outpaddling/RoboCTL/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libgamepad.a:devel/libgamepad

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_PROJECT=	RoboCTL

MAKE_ENV=		EXTRALIBS=-lbluetooth
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	CUTECOM
CUTECOM_DESC=	Install cutecom for Vex debugging

MANPREFIX=	${PREFIX}/share
MAKE_ENV+=	PREFIX=${PREFIX} MANPREFIX=${MANPREFIX} LOCALBASE=${LOCALBASE}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCUTECOM}
RUN_DEPENDS+=	cutecom:comms/cutecom
.endif

pre-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} depend)

post-install:
	(cd ${WRKSRC}/Commands/NXTRemote && ${SETENV} ${MAKE_ENV} ${MAKE})
	${INSTALL_PROGRAM} ${WRKSRC}/Commands/NXTRemote/nxtremote ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/lego_bluetooth_config ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/Commands/NXTRemote/nxtremote.1 ${STAGEDIR}${MANDIRS}/man1

.include <bsd.port.mk>
