# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	viewnior
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://cloud.github.com/downloads/xsisqox/Viewnior/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Fast and simple image viewer

LICENSE=	GPLv3

USES=		gmake pkgconfig shared-mime-info
USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk20
INSTALLS_ICONS=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

post-patch:
	@${REINPLACE_CMD} -e 's|$$(prefix)/$$(DATADIRNAME)/locale|$$(datarootdir)/locale|' \
		${WRKSRC}/po/Makefile.in.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
