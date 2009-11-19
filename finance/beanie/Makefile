# New ports collection makefile for:	beanie
# Date created:		15 October 2008
# Whom:			Dermot Tynan <dtynan@kalopa.com>
#
# $FreeBSD$
#

PORTNAME=	beanie
PORTVERSION=	0.8.2
CATEGORIES=	finance
MASTER_SITES=	SF

MAINTAINER=	dtynan@kalopa.com
COMMENT=	Beanie is a fully-fledged accounting and payroll system

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2
BUILD_DEPENDS=	dbow:${PORTSDIR}/databases/dbow

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${CP} ${WRKSRC}/beanie.mk.sample $(WRKSRC)/beanie.mk
	@${CP} ${WRKSRC}/tmac/lhead.sample.r ${WRKSRC}/tmac/lhead.r

.include <bsd.port.mk>
