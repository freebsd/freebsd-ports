# Created by: Dermot Tynan <dtynan@kalopa.com>
# $FreeBSD$

PORTNAME=	beanie
PORTVERSION=	0.8.2
CATEGORIES=	finance
MASTER_SITES=	SF

MAINTAINER=	dtynan@kalopa.com
COMMENT=	Beanie is a fully-fledged accounting and payroll system

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2
BUILD_DEPENDS=	dbow:${PORTSDIR}/databases/dbow

MAKE_JOBS_UNSAFE=	yes

NO_STAGE=	yes
post-patch:
	@${CP} ${WRKSRC}/beanie.mk.sample $(WRKSRC)/beanie.mk
	@${CP} ${WRKSRC}/tmac/lhead.sample.r ${WRKSRC}/tmac/lhead.r

.include <bsd.port.mk>
