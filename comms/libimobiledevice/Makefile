# $FreeBSD$

PORTNAME=	libimobiledevice
PORTVERSION=	1.1.5
PORTREVISION?=	0
CATEGORIES?=	comms
MASTER_SITES=	http://www.${PORTNAME}.org/downloads/

MAINTAINER?=	avilla@FreeBSD.org
COMMENT?=	Library to communicate with Apple iOS devices

LICENSE?=	LGPL21

SLAVE_PORT?=	no

USES=		pkgconfig
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	openssl_LIBS=-lssl
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if ${SLAVE_PORT} == "no"

LIB_DEPENDS=	gnutls:${PORTSDIR}/security/gnutls \
		tasn1:${PORTSDIR}/security/libtasn1 \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		plist:${PORTSDIR}/devel/libplist \
		usbmuxd:${PORTSDIR}/comms/usbmuxd

USE_GNOME=	glib20
CONFIGURE_ARGS+=--without-cython
USE_CSTD=	gnu89
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS NEWS README

MAN1=		idevice_id.1 idevicebackup.1 idevicebackup2.1 idevicedate.1 \
		idevicedebugserverproxy.1 idevicediagnostics.1 \
		ideviceenterrecovery.1 ideviceimagemounter.1 ideviceinfo.1 \
		idevicepair.1 ideviceprovision.1 idevicescreenshot.1 \
		idevicesyslog.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's, *@ssl_requires@,,' \
		${WRKSRC}/${PORTNAME}*.pc.in
	@${REINPLACE_CMD} -e 's,$$(libdir)/pkgconfig,${PREFIX}/libdata/pkgconfig,g' \
		${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.endif # ${SLAVE_PORT} == "no"

.include <bsd.port.mk>
