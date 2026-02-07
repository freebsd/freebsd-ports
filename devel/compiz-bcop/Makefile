PORTNAME=	compiz-bcop
PORTVERSION=	0.8.8
PORTREVISION=	5
CATEGORIES=	devel x11-wm
MASTER_SITES=	https://BSDforge.com/projects/source/devel/compiz-bcop/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Code generator for Compiz Fusion Plugins
WWW=		https://forum.compiz-fusion.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash \
		getopt>=0:misc/getopt

USES=		gnome pkgconfig tar:bzip2
USE_GNOME=	libxslt

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/bcop \
		share/bcop/bcop.xslt \
		share/pkgconfig/bcop.pc

post-patch:
	@${REINPLACE_CMD} \
		-e 's|/bin/bash|${LOCALBASE}/bin/bash|' \
		-e 's|getopt|${LOCALBASE}/bin/getopt|' \
		${WRKSRC}/src/bcop.in

.include <bsd.port.mk>
