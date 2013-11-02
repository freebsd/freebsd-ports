# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hinversi
PORTVERSION=	0.8.2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/latest

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Reversi/Othello clone

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=	pathfix
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

NLS_CONFIGURE_ON=	--with-libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_OFF=	--disable-nls
NLS_USES=	gettext

post-patch:
.for file in cgi/Makefile.in human-cli/Makefile.in lib/Makefile.in
	@${REINPLACE_CMD} -e \
		'/AM_CFLAGS/s|-O3|| ; \
		 /_la_LIBADD/s|=$$|= $$(LTLIBINTL)|' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
