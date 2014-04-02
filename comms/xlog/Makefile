# Created by: Patrick Gardella <patrick@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xlog
PORTVERSION=	2.0.12
CATEGORIES=	comms hamradio
MASTER_SITES=	SAVANNAH
MASTER_SITE_SUBDIR=	xlog

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Amateur Radio logging application

LICENSE=	GPLv3

LIB_DEPENDS=	libhamlib.so:${PORTSDIR}/comms/hamlib

USES=		pkgconfig shared-mime-info
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-mime-update
CONFIGURE_ENV+=	ac_cv_c_compiler_gnu=no
MAKE_ARGS=	PREFIX=/${PREFIX}

OPTIONS_DEFINE=	NLS DOCS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

DESKTOP_ENTRIES="${PORTNAME}" "${COMMENT}" "${PORTNAME}.xpm" \
	"${PORTNAME}" "Utility;" ${FALSE}

post-patch:
	@${REINPLACE_CMD} -e 's/@INSTALL_DATA@/${INSTALL} -m 644/' \
		${WRKSRC}/data/desktop/Makefile.in

.include <bsd.port.mk>
