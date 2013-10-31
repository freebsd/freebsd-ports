# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Readonly
PORTVERSION=	1.03
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-XS-${PORTVERSION_XS}${EXTRACT_SUFX}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Facility for creating read-only scalars, arrays, hashes

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	DIR="${PORTNAME}-XS-${PORTVERSION_XS}"
PORTVERSION_XS=	1.05

post-patch:
	${MV} ${WRKDIR}/${PORTNAME}-XS-${PORTVERSION_XS} ${WRKSRC}
	${RM} ${WRKSRC}/*.pl

.include <bsd.port.mk>
