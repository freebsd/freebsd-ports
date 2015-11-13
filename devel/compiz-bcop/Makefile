# Created by: Robert Noland <rnoland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	compiz-bcop
PORTVERSION=	0.8.8
CATEGORIES=	devel x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Code generator for Compiz Fusion Plugins

RUN_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash \
		${LOCALBASE}/bin/getopt:${PORTSDIR}/misc/getopt

GNU_CONFIGURE=	yes

BROKEN=		Does not fetch
USES=		pkgconfig tar:bzip2
USE_GNOME=	libxslt

post-patch:
	@${REINPLACE_CMD} \
		-e 's|/bin/bash|${LOCALBASE}/bin/bash|' \
		-e 's|getopt|${LOCALBASE}/bin/getopt|' \
		${WRKSRC}/src/bcop.in
	@${REINPLACE_CMD} -e \
		's|[(]datadir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
