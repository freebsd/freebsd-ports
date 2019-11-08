# Created by: Robert Noland <rnoland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	compiz-bcop
PORTVERSION=	0.8.8
CATEGORIES=	devel x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/ \
		https://BSDforge.com/projects/source/devel/compiz-bcop/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Code generator for Compiz Fusion Plugins

RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash \
		${LOCALBASE}/bin/getopt:misc/getopt

GNU_CONFIGURE=	yes

USES=		gnome pathfix pkgconfig tar:bzip2
USE_GNOME=	libxslt

post-patch:
	@${REINPLACE_CMD} \
		-e 's|/bin/bash|${LOCALBASE}/bin/bash|' \
		-e 's|getopt|${LOCALBASE}/bin/getopt|' \
		${WRKSRC}/src/bcop.in

.include <bsd.port.mk>
