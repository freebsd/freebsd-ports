# Created by: Charlie Kester <corky1951#comcast.net>
# $FreeBSD$

PORTNAME=	osmo
PORTVERSION=	0.2.12
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}-pim/${PORTNAME}-pim/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Personal organizer

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libical.so:${PORTSDIR}/devel/libical \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libgringotts.so:${PORTSDIR}/security/libgringotts \
		libgtkspell.so:${PORTSDIR}/textproc/gtkspell \
		libwebkitgtk-1.0.so:${PORTSDIR}/www/webkit-gtk2

USES=		gettext gmake pkgconfig
USE_GNOME=	gtk20 libxml2
USE_SQLITE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBARCHIVE_CFLAGS=" " LIBARCHIVE_LIBS="-larchive"
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

POFILES=	bg ca cs da de el en_GB es fi fr gl gl_ES hu it ja lt nl \
		pl pt pt_BR ro ru sv te tr uk ur ur_PK zh_CN

post-build:
.for p in ${POFILES}
	(cd ${WRKSRC}/po && ${LOCALBASE}/bin/msgfmt -c ${p}.po -o ${p}.mo)
.endfor

.include <bsd.port.mk>
