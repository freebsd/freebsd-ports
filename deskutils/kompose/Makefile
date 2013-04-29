# Created by: Lauri Watts <lauri@kde.org>
# $FreeBSD$

PORTNAME=	kompose
PORTVERSION=	0.5.3
PORTREVISION=	7
CATEGORIES=	deskutils kde
MASTER_SITES=	BERLIOS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full-screen task manager similar to Expose(tm)

EXTRA_PATCHES=	${PORTSDIR}/x11/kde3/files/extrapatch-old_configure

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool
USE_EFL=	imlib2
INSTALLS_ICONS=	yes

DOCSDIR=	share/doc/HTML/en/${PORTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2 ||g' ${WRKSRC}/configure

.include <bsd.port.mk>
