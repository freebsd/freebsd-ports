# New ports collection makefile for:	egypt
# Date created:		21 April 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	egypt
PORTVERSION=	1.7
CATEGORIES=	devel perl5
MASTER_SITES=	http://www.gson.org/egypt/download/ CENKES

MAINTAINER=	corky1951@comcast.net
COMMENT=	Create call graphs of C programs

USE_PERL5_RUN=	yes
PERL_CONFIGURE=	yes
MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME} %%SITE_PERL%%/%%PERL_ARCH%%/auto/${PORTNAME}/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/${PORTNAME}

.include <bsd.port.mk>
