# Created by: Peter Pentchev <roam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-FreeDB
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Get the CDID of an audio CD and query the FreeDB servers

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CDDB-File>=0:audio/p5-CDDB-File  \
		p5-Moo>=0:devel/p5-Moo
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		alias perl5
USE_PERL5=	configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Net/FreeDB/FreeDB.so

.include <bsd.port.mk>
