# New ports collection makefile for:	gscan2pdf
# Date created:		4 September 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gscan2pdf
PORTVERSION=	0.6.1
CATEGORIES=	graphics
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Produce PDF from scanned documents

RUN_DEPENDS=	tiff2pdf:${PORTSDIR}/graphics/tiff \
		${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2

USE_PERL5_RUN=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -Ee 's!tiff2pdf (.*) \$$options!tiff2pdf \$$options \1!' ${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
