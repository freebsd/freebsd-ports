# Created by: Andreev Maxim
# $FreeBSD$

PORTNAME=	xarchiver
PORTVERSION=	0.5.4.6
CATEGORIES=	archivers

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Desktop-agnostic GTK+2 frontend to various archiving tools

LICENSE=	GPLv2

RUN_DEPENDS=	xdg-open:devel/xdg-utils \
		7zr:archivers/p7zip \
		zip:archivers/zip \
		zipinfo:archivers/unzip

USE_GITHUB=	yes
GH_ACCOUNT=	ib
GH_TAGNAME=	bb5fce0

USES=		desktop-file-utils gmake pkgconfig tar:bzip2
USE_GNOME=	glib20 gtk20 intltool
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_GROUP=	FORMATS
OPTIONS_GROUP_FORMATS=	ARJ LZO RAR
OPTIONS_SUB=	yes

FORMATS_DESC=	Additional compression formats support
ARJ_DESC=	ARJ compression support
LZO_DESC=	LZO compression support
RAR_DESC=	RAR compression support

ARJ_RUN_DEPENDS=	arj:archivers/arj
LZO_RUN_DEPENDS=	lzop:archivers/lzop
RAR_RUN_DEPENDS=	unrar:archivers/unrar \
			rar:archivers/rar

NLS_USES=	gettext
NLS_CPPFLAGS+=	-I${LOCALBASE}/include
NLS_LDFLAGS+=	-L${LOCALBASE}/lib

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e 's|doc||g' ${WRKSRC}/Makefile.in
post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's| po | |g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
