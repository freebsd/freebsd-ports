# New ports collection makefile for:	Ogle KDE GUI
# Date created:         Tue Jul 9 20:24:02 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	okle
PORTVERSION=	0.2.2
CATEGORIES=	graphics kde
MASTER_SITES=	http://okle.sourceforge.net/

MAINTAINER=	lioux@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/ogle/libdvdcontrol.so.7:${PORTSDIR}/graphics/ogle \
		autoconf:${PORTSDIR}/devel/autoconf
RUN_DEPENDS=	ogle:${PORTSDIR}/graphics/ogle

USE_KDELIBS_VER=	3
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ogle-dir=${LOCALBASE}/bin \
		--with-ogle-includes=${LOCALBASE}/include \
		--with-ogle-libs=${LOCALBASE}/lib/ogle

# location of okle ogle_gui
DVDP_UI=${PREFIX}/lib/okle/ogle_gui
OGLE=${LOCALBASE}/bin/ogle

pre-everything::
.ifndef(WITH_DVD_DEVICE)
	@${ECHO_MSG} '===> The default DVD device is /dev/acd0c'
	@${ECHO_MSG} "===> You can choose any DVD device at Ogle's command line"
	@${ECHO_MSG} '===> Define WITH_DVD_DEVICE if you want to change the default'
	@${ECHO_MSG} "===> For example, 'make WITH_DVD_DEVICE=\"/dev/somedevice\"'"
.endif

pre-configure:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf && ${LOCALBASE}/bin/autoheader

post-install:
	@${MKDIR} ${PREFIX}/lib/okle
	@${INSTALL_PROGRAM} ${WRKSRC}/src/ogle_gui ${PREFIX}/lib/okle
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.pre.mk>

.ifdef(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
DEFAULT_DVD_DEVICE=/dev/acd0c
.endif

post-patch:
# wrapper hack to allow ogle to have both ogle-gui and oKle installed
# at same time
	@${SED} -e "s|%%DVDP_UI%%|${DVDP_UI}|; \
		s|%%ENV%%|${SETENV}|; \
		s|%%OGLE%%|${OGLE}|" \
		${FILESDIR}/wrapper.sh > \
		${WRKDIR}/wrapper.sh
	@${REINPLACE_CMD} -E -e 's|^(Exec=).+$$|\1${PORTNAME}|' \
		${WRKSRC}/src/okle.desktop
# point to specific device
	@${REINPLACE_CMD} -e "s|\"/dev/dvd\"|\"${DEFAULT_DVD_DEVICE}\"|" \
		${WRKSRC}/src/okle_win.cpp
# do not use version names
	@${REINPLACE_CMD} -E -e 's|^(PACKAGE[[:space:]]+=).+$$|\1${PORTNAME}|' \
		${WRKSRC}/po/Makefile.in

.include <bsd.port.post.mk>
