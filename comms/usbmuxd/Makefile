# $FreeBSD$

PORTNAME=	usbmuxd
PORTVERSION=	1.0.7
PORTREVISION=	3
CATEGORIES=	comms
MASTER_SITES=	http://www.libimobiledevice.org/downloads/

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Daemon for multiplexing connections over USB to an iPhone/iPod Touch

LIB_DEPENDS=	plist:${PORTSDIR}/devel/libplist

USE_BZIP2=	yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS README README.devel

OPTIONS_DEFINE=	INOTIFY

INOTIFY_DESC=	Use inotify instead of polling (saves energy)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MINOTIFY}
LIB_DEPENDS+=	inotify:${PORTSDIR}/devel/libinotify
.else
CMAKE_ARGS+=	-DWANT_INOTIFY:BOOL=FALSE
.endif

.if ${OSVERSION} <= 800107 || ${OSVERSION} >= 900000 && ${OSVERSION} <= 900002
IGNORE=		requires libusb 1.0.3
.endif

pre-configure:
	${REINPLACE_CMD} -e 's,$${LIB_SUFFIX}/pkgconfig,data/pkgconfig,' \
		${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
		${WRKSRC}/Modules/FindInotify.cmake

pre-install:
	${REINPLACE_CMD} -e '1 s,python,env python,' \
		${WRKSRC}/python-client/*.py

post-install:
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/python-client/*.py \
		${DATADIR}/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
