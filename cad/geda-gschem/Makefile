# New ports collection makefile for:	geda
# Date created:			4 April 2001
# Whom:				bruno schwander <bruno@tinkerbox.org>
#
# $FreeBSD$
#

PORTNAME=	gschem
PORTVERSION=	1.4.3
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/release/v1.4/${PORTVERSION}/ \
		http://geda.seul.org/release/v1.4/${PORTVERSION}/
PKGNAMEPREFIX=	geda-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	The gEDA's electronic schematic capture tool

RUN_DEPENDS=	${LOCALBASE}/share/geda/sym:${PORTSDIR}/cad/geda-symbols
LIB_DEPENDS=	geda.33:${PORTSDIR}/cad/libgeda

DOCSDIR=	${PREFIX}/share/doc/geda
DATADIR=	${PREFIX}/share/geda

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--enable-gdgeda --with-docdir=${DOCSDIR} \
		--disable-update-mime-database \
		--disable-update-desktop-database
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gschem.1

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -E \
		-e "s,^(DATADIR[[:space:]]*=[[:space:]]*)gEDA,\1geda," \
		${WRKSRC}/configure

.include <bsd.port.mk>
