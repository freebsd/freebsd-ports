# Created by: Andreev Maxim
# $FreeBSD$

PORTNAME=	xarchiver
PORTVERSION=	0.5.3
CATEGORIES=	archivers
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME:tl}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Desktop-agnostic GTK+2 frontend to various archiving tools

LICENSE=	GPLv2

RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils \
	7zr:${PORTSDIR}/archivers/p7zip \
	zip:${PORTSDIR}/archivers/zip

USES=		tar:bzip2 gmake pkgconfig desktop-file-utils
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
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|doc||g' ${WRKSRC}/Makefile.in
.endif
.if empty(PORT_OPTIONS:MNLS)
	@${REINPLACE_CMD} -e 's| po | |g' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
