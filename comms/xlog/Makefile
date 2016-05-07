# Created by: Patrick Gardella <patrick@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xlog
PORTVERSION=	2.0.13
CATEGORIES=	comms hamradio
MASTER_SITES=	SAVANNAH

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Amateur Radio logging application

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhamlib.so:comms/hamlib

USES=		pkgconfig shared-mime-info
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-mime-update
CONFIGURE_ENV+=	ac_cv_c_compiler_gnu=no
MAKE_ARGS=	PREFIX=/${PREFIX}

LIBS+=		-lm

OPTIONS_DEFINE=	NLS DOCS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

DESKTOP_ENTRIES="${PORTNAME}" "${COMMENT}" "${PORTNAME}" \
	"${PORTNAME}" "Utility;" false

.include <bsd.port.mk>
