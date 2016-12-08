# Created by: Florian Unglaub <f.unglaub@googlemail.com>
# $FreeBSD$

PORTNAME=	devd-notifier
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	GHC http://roladder.net/~flo/dist/

MAINTAINER=	f.unglaub@googlemail.com
COMMENT=	Daemon notifying the user about devd(8) events \
		with libnotify

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libnotify.so:devel/libnotify

USES=		pkgconfig
PLIST_FILES=	bin/devd-notifier \
		man/man1/devd-notifier.1.gz
USE_GITHUB=	yes
GH_ACCOUNT=	funglaub

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
