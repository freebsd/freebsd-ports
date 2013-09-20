# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	roboctl
PORTVERSION=	0.3.7
CATEGORIES=	devel
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://jbacon.dyndns.org/~bacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	API and tools for communicating with Lego and Vex robots

BUILD_DEPENDS=	${LOCALBASE}/lib/libgamepad.a:${PORTSDIR}/devel/libgamepad

MAKE_ENV=	EXTRALIBS=-lbluetooth
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	CUTECOM
CUTECOM_DESC=	Install cutecom for Vex debugging

MAN1=		legoctl.1 vexctl.1 nxtremote.1
MAN3=		roboctl.3

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCUTECOM}
RUN_DEPENDS+=	cutecom:${PORTSDIR}/comms/cutecom
.endif

pre-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} depend)

post-install:
	(cd ${WRKSRC}/Commands/NXTRemote; ${MAKE})
	${INSTALL_PROGRAM} ${WRKSRC}/Commands/NXTRemote/nxtremote ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/lego_bluetooth_config ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/Commands/NXTRemote/nxtremote.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
