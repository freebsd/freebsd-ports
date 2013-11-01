# Created by: Peter Pentchev <roam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-FreeDB
PORTVERSION=	0.08
PORTREVISION=	2
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Get the CDID of an audio CD and query the FreeDB servers

BUILD_DEPENDS=	p5-CDDB-File>=0:${PORTSDIR}/audio/p5-CDDB-File
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
