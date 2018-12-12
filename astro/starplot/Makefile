# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	starplot
PORTVERSION=	0.95.5
PORTREVISION=	8
CATEGORIES=	astro
MASTER_SITES=	http://starplot.org/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3-dimensional viewer for star charts

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		compiler:c++11-lang gmake gnome localbase:ldflags pathfix \
		gettext pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|$$(docdir)/examples|${EXAMPLESDIR}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
