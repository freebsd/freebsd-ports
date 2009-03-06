# New ports collection makefile for:	fotofix
# Date created:		7 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fotofix
PORTVERSION=	0.01.1.79
CATEGORIES=	graphics
MASTER_SITES=	http://mirror.mcx2.org/ \
		http://prima.eu.org/cgi-bin/cvsweb.cgi/apps/fotofix/fotofix/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Simple image viewer

RUN_DEPENDS=	p5-Prima>=1.21:${PORTSDIR}/x11-toolkits/p5-Prima \
		IPA>=1.03:${PORTSDIR}/graphics/IPA

USE_BZIP2=	yes
USE_PERL5_RUN=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
