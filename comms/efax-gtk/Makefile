# New ports collection makefile for:   efax-gtk
# Whom:                                Jean-Baptiste Quenot <jb.quenot@caraldi.com>
# Date Created:                        2004-02-29 10:33:43
#
# $FreeBSD$
#

PORTNAME=		efax-gtk
PORTVERSION=		3.2.9
CATEGORIES=		comms
MASTER_SITES=		SF
EXTRACT_SUFX=		.src.tgz

MAINTAINER=		pawel@FreeBSD.org
COMMENT=		GUI front end for the efax fax program

LICENSE=		GPLv2

LIB_DEPENDS=		cxx-gtk-utils-2-2.0:${PORTSDIR}/x11-toolkits/c++-gtk-utils \
			sigc-1.2.5:${PORTSDIR}/devel/libsigc++12 \
			tiff:${PORTSDIR}/graphics/tiff
RUN_DEPENDS=		ggv:${PORTSDIR}/print/ggv

USE_ICONV=		yes
USE_GHOSTSCRIPT_RUN=	yes
USE_GNOME=		gtk20
GNU_CONFIGURE=		yes
USE_GCC=		4.4+
MAKE_JOBS_SAFE=		yes

MAN1=			efax.1 efix.1 efax-gtk.1

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} -lintl

CONFIGURE_ARGS+=	--with-gtk-version=gtk2

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-install:
	@${ECHO}
	@${ECHO_CMD} "********************************************************************************"
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} "********************************************************************************"
	@${ECHO}

.include <bsd.port.mk>
