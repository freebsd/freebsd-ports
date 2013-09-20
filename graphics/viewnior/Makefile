# Created by: nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	viewnior
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://cloud.github.com/downloads/xsisqox/Viewnior/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Fast and simple image viewer

LICENSE=	GPLv3

BUILD_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info
RUN_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_AUTOTOOLS=	autoconf
USE_GNOME=	glib20 gtk20
INSTALLS_ICONS=	yes

MAN1=		viewnior.1

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=	NLS
OPTIONS_DEFAULT=	NLS

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/${MAN1} ${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
