# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	leafpad
PORTVERSION=	0.8.18.1
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	SAVANNAH
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	GTK+ based simple text editor

USE_GNOME=	gtk20 intlhack
USES=		desktop-file-utils gmake pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-chooser
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL README

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.options.mk>

post-extract:
	@${CHMOD} a+x ${WRKSRC}/install-sh

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|SUBDIRS = src data po|SUBDIRS = src data|g' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
