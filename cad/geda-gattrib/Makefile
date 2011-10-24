# New ports collection makefile for:	geda-gattrib
# Date created:			26 June 2006
# Whom:				Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	gattrib
PORTVERSION=	1.4.3
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/release/v1.4/${PORTVERSION}/ \
		http://geda.seul.org/release/v1.4/${PORTVERSION}/
PKGNAMEPREFIX=	geda-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The gEDA's attribute editor

RUN_DEPENDS=	${LOCALBASE}/share/geda/sym:${PORTSDIR}/cad/geda-symbols
LIB_DEPENDS=	geda.33:${PORTSDIR}/cad/libgeda

DATADIR=	${PREFIX}/share/geda
DOCSDIR=	${PREFIX}/share/doc/geda

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 glib20
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--with-docdir="${DOCSDIR}" --disable-update-mime-database \
		--disable-update-desktop-database
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -E \
		-e "s,^(DATADIR[[:space:]]*=[[:space:]]*)gEDA,\1geda," \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|>n_bytes|>x_n_bytes|g' \
		-e 's|>text_size|>x_text_size|g' \
		${WRKSRC}/src/gtkitementry_2_2.c

.include <bsd.port.mk>
