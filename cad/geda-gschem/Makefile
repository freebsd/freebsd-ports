# Created by: bruno schwander <bruno@tinkerbox.org>
# $FreeBSD$

PORTNAME=	gschem
PORTVERSION=	1.4.3
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/release/v1.4/${PORTVERSION}/ \
		http://geda.seul.org/release/v1.4/${PORTVERSION}/
PKGNAMEPREFIX=	geda-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The gEDA's electronic schematic capture tool

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
RUN_DEPENDS=	geda-symbols>0:${PORTSDIR}/cad/geda-symbols
LIB_DEPENDS=	libgeda.so:${PORTSDIR}/cad/libgeda

DOCSDIR=	${PREFIX}/share/doc/geda
DATADIR=	${PREFIX}/share/geda

GNU_CONFIGURE=	yes
USES=		desktop-file-utils gmake pkgconfig
USE_GNOME=	gtk20
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--enable-gdgeda --with-docdir=${DOCSDIR} \
		--disable-update-mime-database \
		--disable-update-desktop-database
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -E \
		-e "s,^(DATADIR[[:space:]]*=[[:space:]]*)gEDA,\1geda," \
		${WRKSRC}/configure

.include <bsd.port.mk>
