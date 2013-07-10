# Created by: Jean-Baptiste Quenot <jb.quenot@caraldi.com>
# $FreeBSD$

PORTNAME=	efax-gtk
PORTVERSION=	3.2.12
CATEGORIES=	comms
MASTER_SITES=	SF
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	GUI frontend for efax program

LICENSE=	GPLv2

LIB_DEPENDS=	sigc-1.2.5:${PORTSDIR}/devel/libsigc++12 \
		cxx-gtk-utils-2-2.2:${PORTSDIR}/x11-toolkits/c++-gtk-utils
RUN_DEPENDS=	ggv:${PORTSDIR}/print/ggv

USES=		pkgconfig
USE_GHOSTSCRIPT_RUN=yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_GCC=	4.4+
MAKE_JOBS_SAFE=	yes

CONFLICTS=	efax-[0-9]*

MAN1=		efax.1 efix.1 efax-gtk.1

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread -lintl

CONFIGURE_ARGS+=--with-gtk-version=gtk2

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_OFF=	--disable-nls
NLS_USES=		gettext

.include <bsd.port.options.mk>

post-install:
	@${ECHO}
	@${ECHO_CMD} "********************************************************************************"
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} "********************************************************************************"
	@${ECHO}

.include <bsd.port.mk>
