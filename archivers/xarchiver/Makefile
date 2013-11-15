# Created by: Andreev Maxim
# $FreeBSD$

PORTNAME=	xarchiver
PORTVERSION=	0.5.2
PORTREVISION=	6
CATEGORIES=	archivers
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Desktop-agnostic GTK+2 frontend to various archiving tools

LICENSE=	GPLv2

RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

USES=		gmake pkgconfig desktop-file-utils
USE_BZIP2=	yes
USE_GNOME=	glib20 gtk20 intltool
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DOCS NLS

.include <bsd.port.options.mk>

.if !empty(PORT_OPTIONS:MNLS)
USES+=		gettext
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|;multipart/x-zip||' \
		${WRKSRC}/xarchiver.desktop.in

.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|doc||g' ${WRKSRC}/Makefile.in
.endif
.if empty(PORT_OPTIONS:MNLS)
	@${REINPLACE_CMD} -e 's| po | |g' ${WRKSRC}/Makefile.in
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
