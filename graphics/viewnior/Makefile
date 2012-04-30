# New Ports collection makefile for:	viewnior
# Date created:		2012-04-20
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	viewnior
PORTVERSION=	1.3
CATEGORIES=	graphics
MASTER_SITES=	http://cloud.github.com/downloads/xsisqox/Viewnior/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Viewnior is a fast and simple image viewer

LICENSE=	GPLv3

BUILD_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info
RUN_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20 intltool pkgconfig
INSTALLS_ICONS=	yes

MAN1=		viewnior.1

PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README TODO

OPTIONS=	NLS		"Enable gettext support" on

.include <bsd.port.options.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/${MAN1} ${MAN1PREFIX}/man/man1
# Documentations
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
