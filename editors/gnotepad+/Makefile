# Created by: brett@peloton.physics.montana.edu
# $FreeBSD$

PORTNAME=	gnotepad+
PORTVERSION=	1.3.3
PORTREVISION=	10
CATEGORIES=	editors www gnome
MASTER_SITES=	SF/gnotepad/gnotepad-stable/${PORTVERSION} \
		SF/gnotepad/gnotepad%20User_s%20Manual/${DOCVERSION}:doc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple GTK-based text/HTML editor

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USE_XORG=	xpm
USE_GNOME=	gnomeprefix gtk12
USES=		gettext
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--disable-gnome

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DOCVERSION=	1.2.0

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_DISTFILES=	${PORTNAME}-help-${DOCVERSION}${EXTRACT_SUFX}:doc

.include <bsd.port.options.mk>

post-extract:
.if ${PORT_OPTIONS:MDOCS}
	@${MV} ${WRKSRC}/docs ${WRKSRC}/docs.old
	@${CP} -R ${WRKDIR}/${PORTNAME}-help-${DOCVERSION}/docs ${WRKSRC}/docs
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\(use_gtkhtml=\)yes|\1no|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} '/destdir/ s|gnulocaledir)|DESTDIR)$$(&|' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
