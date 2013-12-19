# Created by: Florian Unglaub <f.unglaub@googlemail.com>
# $FreeBSD$

PORTNAME=	devd-notifier
PORTVERSION=	0.1
CATEGORIES=	deskutils
MASTER_SITES=	https://cloud.github.com/downloads/funglaub/devd-notifier/\
		http://roladder.net/~flo/dist/

MAINTAINER=	f.unglaub@googlemail.com
COMMENT=	A daemon notifying the user about devd(8) events \
		with libnotify

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify

USES=		pkgconfig
MAN1=		devd-notifier.1
PLIST_FILES=	bin/devd-notifier
MANCOMPRESSED=	yes

NO_STAGE=	yes
pre-everything::
	@${ECHO_MSG} "You can build devd-notifier with your own config.h using the DEVD-NOTIFIER_CONF knob:"
	@${ECHO_MSG} "make DEVD-NOTIFIER_CONF=/path/to/devd-notifier/config.h install clean"

post-extract:
.if defined(DEVD-NOTIFIER_CONF)
	@${ECHO_MSG} "creating config.h from ${DEVD-NOTIFIER_CONF}"
	@${CP} ${DEVD-NOTIFIER_CONF} ${WRKSRC}/config.h
.endif

post-patch:
	@${REINPLACE_CMD} 's|/usr/local|${PREFIX}|' ${WRKSRC}/config.mk

.include <bsd.port.mk>
