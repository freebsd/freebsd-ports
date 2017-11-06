# Created by: Charlie Kester <corky1951#comcast.net>
# $FreeBSD$

PORTNAME=	osmo
PORTVERSION=	0.2.14
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}-pim/${PORTNAME}-pim/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Personal organizer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libical.so:devel/libical \
		libnotify.so:devel/libnotify \
		libgringotts.so:security/libgringotts \
		libgtkspell.so:textproc/gtkspell \
		libwebkitgtk-1.0.so:www/webkit-gtk2

USES=		gettext gmake libarchive pkgconfig sqlite
USE_GNOME=	gtk20 libxml2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

POFILES=	bg ca cs da de el en_GB es fi fr gl gl_ES he hu it ja lt \
		nl pl pt pt_BR ro ru sr sv te tr uk ur ur_PK zh_CN

post-build:
.for p in ${POFILES}
	(cd ${WRKSRC}/po && ${LOCALBASE}/bin/msgfmt -c ${p}.po -o ${p}.mo)
.endfor

.include <bsd.port.mk>
