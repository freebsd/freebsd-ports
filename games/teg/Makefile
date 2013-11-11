# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	teg
PORTVERSION=	0.11.2
PORTREVISION=	6
CATEGORIES=	games gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Turn-based strategy game for GNOME

USES=		pathfix gmake iconv pkgconfig
USE_GNOME=	gnomeprefix intlhack libgnomeui
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
CONFIGURE_ARGS=	--disable-ggz

GCONF_SCHEMAS=	teg.schemas

post-patch:
	@${GREP} -lR " LIST_NEXT" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's| LIST_NEXT| TEG_LIST_NEXT|g'
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|pl||g' \
		${WRKSRC}/docs/gnome-help/Makefile.in

.include <bsd.port.mk>
