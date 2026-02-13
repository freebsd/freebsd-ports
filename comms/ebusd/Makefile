PORTNAME=	ebusd
PORTVERSION=	26.1
CATEGORIES=	comms

MAINTAINER=	samm@FreeBSD.org
COMMENT=	Daemon for communication with eBUS heating systems
WWW=		https://github.com/john30/ebusd/wiki

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf compiler:c++11-lang localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	john30

USE_RC_SUBR=	ebusd

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include

USERS=		ebusd
GROUPS=		ebusd

LOGDIR=		/var/log/${PORTNAME}
RUNDIR=		/var/run/${PORTNAME}

PLIST_SUB=	GROUP=${GROUPS} \
		LOGDIR=${LOGDIR} \
		RUNDIR=${RUNDIR} \
		USER=${USERS}

OPTIONS_DEFINE=		MQTT
OPTIONS_DEFAULT=	MQTT
OPTIONS_SUB=		yes
MQTT_DESC=		MQTT protocol support

MQTT_LIB_DEPENDS=	libmosquitto.so:net/mosquitto
MQTT_CONFIGURE_WITH=	mqtt
MQTT_VARS=		LIBS+=-lmosquitto

post-install:
	${MKDIR} ${STAGEDIR}${LOGDIR}
	${MKDIR} ${STAGEDIR}${RUNDIR}

.include <bsd.port.mk>
