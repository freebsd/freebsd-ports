# Created by: brett@peloton.physics.montana.edu
# $FreeBSD$

PORTNAME=	gnotepad+
PORTVERSION=	1.3.3
PORTREVISION=	8
CATEGORIES=	editors www gnome
MASTER_SITES=	SF/gnotepad/gnotepad-stable/${PORTVERSION} \
		SF/gnotepad/gnotepad%20User_s%20Manual/${DOCVERSION}:doc
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:DEFAULT
.if !defined(NOPORTDOCS)
DISTFILES+=	${PORTNAME}-help-${DOCVERSION}${EXTRACT_SUFX}:doc
.endif

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple GTK-based text/HTML editor

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USE_XORG=	xpm
WANT_GNOME=	yes
USE_GNOME=	gnomeprefix gtk12
USES=		gettext
GNU_CONFIGURE=	yes

MAN1=		gnp.1

CONFIGURE_ARGS=	--disable-gnome

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DOCVERSION=	1.2.0

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if defined(NOPORTDOCS)
PLIST_SUB+=	NOPORTDOCS=""
.else
PLIST_SUB+=	NOPORTDOCS="@comment "
.endif

post-extract:
.if !defined(NOPORTDOCS)
	@${MV} ${WRKSRC}/docs ${WRKSRC}/docs.old
	@${CP} -R ${WRKDIR}/${PORTNAME}-help-${DOCVERSION}/docs ${WRKSRC}/docs
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\(use_gtkhtml=\)yes|\1no|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
