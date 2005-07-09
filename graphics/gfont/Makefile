# New ports collection makefile for:	gfont
# Date created:			09-Sep-1997
# Whom:				Ralf S. Engelschall <rse@engelschall.com>
#
# $FreeBSD$
#

PORTNAME=	gfont
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	graphics print www
MASTER_SITES=	ftp://ftp.ossp.org/pkg/tool/gfont/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphics Font - Create GIF image rendered with TeX-available Font

BUILD_DEPENDS=	gsftopk:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	gsftopk:${PORTSDIR}/print/teTeX

USE_GHOSTSCRIPT_BUILD=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes

MAN1=		gfont.1

post-patch:
	@${PERL} -pi -e 's|^CFLAGS=|#CFLAGS=|g' ${WRKSRC}/configure

.include <bsd.port.mk>
