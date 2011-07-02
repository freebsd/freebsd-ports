# New ports collection makefile for:	hinversi
# Date created:		2 April 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hinversi
PORTVERSION=	0.8.2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/latest

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Reversi/Othello clone

OPTIONS=	NLS "Native Language Support via gettext utilities" on

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USE_GNOME=	gnomehack
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

MAN1=		hinversi-cli.1

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--with-libintl-prefix=${LOCALBASE}
PLIST_SUB+=	NLS=""
.endif

post-patch:
.for file in cgi/Makefile.in human-cli/Makefile.in lib/Makefile.in
	@${REINPLACE_CMD} -e \
		'/AM_CFLAGS/s|-O3|| ; \
		 /_la_LIBADD/s|=$$|= $$(LTLIBINTL)|' ${WRKSRC}/${file}
.endfor

.include <bsd.port.post.mk>
