PORTNAME=	usbmuxd
DISTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	https://github.com/libimobiledevice/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Daemon for multiplexing connections over USB to iPhone/iPod Touch

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING.GPLv2
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING.GPLv3

LIB_DEPENDS=	libplist-2.0.so:devel/libplist \
		libimobiledevice-1.0.so:comms/libimobiledevice

USES=		autoreconf cpe libtool localbase pathfix pkgconfig tar:bzip2
CPE_VENDOR=	nikias_bassen

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-systemd

SUB_LIST=	USERS=${USERS} \
		GROUPS=${GROUPS}

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PLIST_FILES=	man/man8/${PORTNAME}.8.gz \
		sbin/${PORTNAME}
PORTDOCS=	AUTHORS NEWS README.md

OPTIONS_DEFINE=		DEVD DOCS
OPTIONS_DEFAULT=	DEVD

DEVD_SUB_FILES=		${PORTNAME}.conf
DEVD_PLIST_FILES=	etc/devd/${PORTNAME}.conf

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

post-install-DEVD-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/devd
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.conf ${STAGEDIR}${PREFIX}/etc/devd

.include <bsd.port.mk>
