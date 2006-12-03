# New ports collection makefile for:	gscan2pdf
# Date created:		4 September 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gscan2pdf
PORTVERSION=	0.8.3
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Produce PDF from scanned documents

RUN_DEPENDS=	tiff2pdf:${PORTSDIR}/graphics/tiff \
		scanimage:${PORTSDIR}/graphics/sane-backends \
		p5-Gtk2>=1.112:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-gettext>=1.05:${PORTSDIR}/devel/p5-Locale-gettext

USE_PERL5=	yes
USE_GETTEXT=	yes
PERL_CONFIGURE=	yes
USE_GMAKE=	yes
MAN1=		${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e 's/--parents/-p/g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
