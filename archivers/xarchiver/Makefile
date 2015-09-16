# Created by: Andreev Maxim
# $FreeBSD$

PORTNAME=	xarchiver
PORTVERSION=	0.5.4
CATEGORIES=	archivers
MASTER_SITES=	SF/${PORTNAME:tl}

MAINTAINER=	danilo@FreeBSD.org
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
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CPPFLAGS+=	-I${LOCALBASE}/include
NLS_LDFLAGS+=	-L${LOCALBASE}/lib

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e 's|doc||g' ${WRKSRC}/Makefile.in
post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's| po | |g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
