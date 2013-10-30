# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Inline-Java
PORTVERSION=	0.53
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Write Perl subroutines and classes in Java

BUILD_DEPENDS=	p5-Inline>=0.44:${PORTSDIR}/devel/p5-Inline \
		p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_JAVA=       yes
JAVA_VERSION=   1.6+
JAVA_OS=        native

MAKE_JOBS_UNSAFE=	yes

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	J2SDK=${JAVA_HOME} </dev/null

.include <bsd.port.mk>
