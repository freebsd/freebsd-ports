# New ports collection makefile for:   dedit
# Date created:        26 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dedit
PORTVERSION=	0.6.2.3
PORTREVISION=	2
CATEGORIES=	editors gnome
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple GNOME i18n editor

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomelibs gnomeprefix gnomehack gtk12 glib12 orbit
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -liconv"

MAN1=		dedit.1
MANLANG=	"" ja

pre-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|\(\$$(datadir)/\)gnome/|\1|g ; \
		 s|dedit.ja.1||'

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/dedit.ja.1 ${MANPREFIX}/man/ja/man1/dedit.1

.include <bsd.port.mk>
