# New ports collection makefile for:	gscan2pdf
# Date created:		4 September 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gscan2pdf
PORTVERSION=	0.8.0
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Produce PDF from scanned documents

RUN_DEPENDS=	tiff2pdf:${PORTSDIR}/graphics/tiff \
		scanimage:${PORTSDIR}/graphics/sane-backends \
		p5-Gtk2>=1.112:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-gettext>=1.05:${PORTSDIR}/devel/p5-Locale-gettext

USE_PERL5_RUN=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
