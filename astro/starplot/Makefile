# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	starplot
PORTVERSION=	0.95.5
PORTREVISION=	7
CATEGORIES=	astro
MASTER_SITES=	http://starplot.org/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3-dimensional viewer for star charts

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		gmake pathfix gettext pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		's|$$(docdir)/examples|${EXAMPLESDIR}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
