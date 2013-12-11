# $FreeBSD$

PORTNAME=	usbmuxd
PORTVERSION=	1.0.8
CATEGORIES=	comms
MASTER_SITES=	http://www.libimobiledevice.org/downloads/

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Daemon for multiplexing connections over USB to iPhone/iPod Touch

LIB_DEPENDS=	libplist.so:${PORTSDIR}/devel/libplist

USE_BZIP2=	yes
USES=		cmake pkgconfig
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS README README.devel

OPTIONS_DEFINE=	INOTIFY

INOTIFY_DESC=	Use inotify instead of polling (saves energy)

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MINOTIFY}
LIB_DEPENDS+=	libinotify.so:${PORTSDIR}/devel/libinotify
CMAKE_ARGS+=	-DWANT_INOTIFY:BOOL=TRUE
.else
CMAKE_ARGS+=	-DWANT_INOTIFY:BOOL=FALSE
.endif

.if ${OSVERSION} <= 800107 || ${OSVERSION} >= 900000 && ${OSVERSION} <= 900002
IGNORE=		requires libusb 1.0.3
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,$${LIB_SUFFIX}/pkgconfig,data/pkgconfig,' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
		${WRKSRC}/Modules/FindInotify.cmake

pre-install:
	@${REINPLACE_CMD} -e '1 s,python,env python,' \
		${WRKSRC}/python-client/*.py

post-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/python-client/*.py ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
