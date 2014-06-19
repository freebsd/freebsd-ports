# Created by: Ashish Shukla <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	irssi-otr
PORTVERSION=	0.3
PORTREVISION=	9
CATEGORIES=	irc
MASTER_SITES=	ftp://download.tuxfamily.org/${MASTER_SITE_SUBDIR}/
MASTER_SITE_SUBDIR=	irssiotr

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Plugin for irssi for Off-the-Record (OTR) messaging

BUILD_DEPENDS=	${LOCALBASE}/include/irssi/src/common.h:${PORTSDIR}/irc/irssi \
		${LOCALBASE}/bin/libgcrypt-config:${PORTSDIR}/security/libgcrypt
LIB_DEPENDS=	libotr.so.2:${PORTSDIR}/security/libotr3 \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt
RUN_DEPENDS=	irssi:${PORTSDIR}/irc/irssi

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake pkgconfig
USE_LDCONFIG=	yes
USE_GNOME=	glib20

PLIST_FILES=	lib/irssi/modules/libotr.so \
		%%DOCSDIR%%/LICENSE %%DOCSDIR%%/README
PLIST_DIRS=	%%DOCSDIR%%

.include <bsd.port.mk>
