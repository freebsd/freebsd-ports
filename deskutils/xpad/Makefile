# Created by: Guillaume Paquet <amyfoub@gmail.com>
# $FreeBSD$

PORTNAME=	xpad
PORTVERSION=	3.1
PORTREVISION=	8
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpad.net/xpad/stable/${PORTVERSION}/+download/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Virtual note-pad system for your X11 desktop

LICENSE=	GPLv3

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

CONFLICTS_INSTALL=	xpad-current-[0-9]*

USE_XORG=	x11 sm
USE_GNOME=	gtk20 gnomehier intltool
USES=	pkgconfig gmake tar:bzip2
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes

NLS_USES=		gettext
NLS_CPPFLAGS=		${CXXFLAGS} -I${LOCALBASE}/include
NLS_LDFLAGS=		-L${LOCALBASE}/lib
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.options.mk>

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|SUBDIRS = autopackage doc src images po|SUBDIRS = autopackage doc src images|' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
