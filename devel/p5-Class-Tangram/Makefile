# Created by: Sergey Skvortsov <skv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Class-Tangram
PORTVERSION=	1.57
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create constructors, accessor, update methods for objects from Tangram

BUILD_DEPENDS=	p5-Set-Object>=0:${PORTSDIR}/devel/p5-Set-Object \
		p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-Tangram>=0:${PORTSDIR}/databases/p5-Tangram
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-patch:
		@${REINPLACE_CMD} -i '' -e 's|\@|\\@|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
