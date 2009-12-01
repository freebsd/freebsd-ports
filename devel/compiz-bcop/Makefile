# New ports collection makefile for:	compiz-bcop
# Date created:				2007-08-15
# Whom:					Robert Noland <rnoland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	compiz-bcop
PORTVERSION=	0.8.4
CATEGORIES=	devel x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	rnoland@FreeBSD.org
COMMENT=	Code generator for Compiz Fusion Plugins

# This annoys me...
RUN_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash \
		${LOCALBASE}/bin/getopt:${PORTSDIR}/misc/getopt

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

USE_GNOME=	pkgconfig libxslt

post-patch:
	@${REINPLACE_CMD} \
		-e 's|/bin/bash|${LOCALBASE}/bin/bash|' \
		-e 's|getopt|${LOCALBASE}/bin/getopt|' \
		${WRKSRC}/src/bcop.in
	@${REINPLACE_CMD} -e \
		's|[(]datadir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
