# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Oogly
PORTVERSION=	0.31
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AWNCORP
PKGNAMEPREFIX=	p5-

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	A Data validation idea that just might be ideal

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=2013-03-31

BUILD_DEPENDS=	p5-Array-Unique>0:${PORTSDIR}/devel/p5-Array-Unique \
		p5-Data-Dumper-Concise>0:${PORTSDIR}/devel/p5-Data-Dumper-Concise \
		p5-Hash-Merge>=0.11:${PORTSDIR}/textproc/p5-Hash-Merge
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Oogly.3

.include <bsd.port.mk>
