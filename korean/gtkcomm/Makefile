# Created by: Junho CHOI <junho.choi@gmail.com>
# $FreeBSD$

PORTNAME=	gtkcomm
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	korean comms
MASTER_SITES=	http://kldp.net/frs/download.php/480/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Serial controlling software, with gtk+ widget

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/local/gulim12.pcf.gz:${PORTSDIR}/korean/baekmukfonts-bdf

USES=		perl5
USE_PERL5=	build
USE_GNOME=	glib20 gtk20
GNU_CONFIGURE=	yes

pre-patch:
	${REINPLACE_CMD} -e 's|-lc_r||; s|DATADIRNAME=lib|DATADIRNAME=share|g' \
	    ${WRKSRC}/configure

.include <bsd.port.mk>
