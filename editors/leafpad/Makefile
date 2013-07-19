# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	leafpad
PORTVERSION=	0.8.18.1
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	SAVANNAH
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ based simple text editor

USE_GNOME=	gtk20 intlhack
USES=		desktop-file-utils
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-chooser
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL README

OPTIONS_DEFINE=	NLS

post-extract:
	@${CHMOD} a+x ${WRKSRC}/install-sh

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=			gettext
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|SUBDIRS = src data po|SUBDIRS = src data|g' \
		${WRKSRC}/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
