# New Ports collection makefile for:	viewnior
# Date created:		2012-04-20
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	viewnior
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://cloud.github.com/downloads/xsisqox/Viewnior/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Viewnior is a fast and simple image viewer

LICENSE=	GPLv3

BUILD_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info
RUN_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20
INSTALLS_ICONS=	yes

MAN1=		viewnior.1

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=	NLS
NLS_DESC=	Native Language Support via gettext
OPTIONS_DEFAULT=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/${MAN1} ${MAN1PREFIX}/man/man1
# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
