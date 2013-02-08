# Created by: riggs
# $FreeBSD$

PORTNAME=	ifp-line
PORTVERSION=	0.3
CATEGORIES=	audio
MASTER_SITES=	SF/ifp-driver/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line interface to iRiver music players

LICENSE=	GPLv2

USE_ICONV=	yes
USE_AUTOTOOLS=	aclocal autoheader automake autoconf
ACLOCAL_ARGS=	-I m4
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		ifp.1
PORTDOCS=	NEWS README TIPS nonroot.sh
PLIST_FILES+=	bin/ifp

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
.else
LDFLAGS+=	-lusb
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/LIBUSB/s|ERROR|WARN|' ${WRKSRC}/configure.ac

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ifp ${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} ifp.1 ${MANPREFIX}/man/man1)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
