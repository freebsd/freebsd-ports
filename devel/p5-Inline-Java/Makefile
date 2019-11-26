# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Inline-Java
PORTVERSION=	0.540
PORTREVISION=	2
CATEGORIES=	devel java perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Write Perl subroutines and classes in Java

LICENSE=	ARTPERL10

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Inline>=0.68:devel/p5-Inline \
		p5-Inline-C>=0.62:devel/p5-Inline-C

USE_JAVA=	yes
JAVA_OS=	native

MAKE_JOBS_UNSAFE=	yes

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	J2SDK=${JAVA_HOME} </dev/null

.include <bsd.port.mk>
