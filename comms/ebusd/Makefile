# $FreeBSD$

PORTNAME=	ebusd
PORTVERSION=	3.3
CATEGORIES=	comms

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Daemon for communication with eBUS heating systems

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libargp.so:devel/argp-standalone

USES=		autoreconf localbase:ldflags

OPTIONS_DEFINE=	MQTT
OPTIONS_DEFAULT=MQTT
MQTT_DESC=	MQTT protocol support

USE_GITHUB=	yes
GH_ACCOUNT=	john30
GH_TAGNAME=	v${PORTVERSION}

USE_RC_SUBR=	ebusd

USERS=		ebusd
GROUPS=		ebusd

LOGDIR=		/var/log/${PORTNAME}
RUNDIR=		/var/run/${PORTNAME}
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes

PLIST_SUB=	USER=${USERS} GROUP=${GROUPS} \
		LOGDIR=${LOGDIR} \
		RUNDIR=${RUNDIR}

MQTT_CONFIGURE_WITH=	mqtt
MQTT_LIB_DEPENDS=	libmosquitto.so:net/mosquitto
MQTT_VARS=		LIBS+=-lmosquitto

post-install:
	${MKDIR} ${STAGEDIR}${LOGDIR}
	${MKDIR} ${STAGEDIR}${RUNDIR}

.include <bsd.port.mk>
