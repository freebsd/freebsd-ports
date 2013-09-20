# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	Unicode-Japanese
PORTVERSION=	0.49
CATEGORIES=	japanese converters perl5
MASTER_SITES=	CPAN

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Perl5 module to handle Japanese character encodings

USES=		perl5
USE_PERL5=	configure

MAN1=		ujconv.1 ujguess.1
MAN3=		Unicode::Japanese.3 Unicode::Japanese::JA.3

NO_STAGE=	yes
.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.include <bsd.port.post.mk>

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:NCCFLAGS=*}
