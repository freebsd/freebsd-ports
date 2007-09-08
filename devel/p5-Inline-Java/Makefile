# ex:ts=8
# Ports collection makefile for:	Inline::Java
# Date created:			Aug 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Inline-Java
PORTVERSION=	0.52
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/P/PA/PATL
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Write Perl subroutines and classes in Java

BUILD_DEPENDS=	p5-Inline>=0.44:${PORTSDIR}/devel/p5-Inline \
		p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_JAVA=       yes
JAVA_VERSION=   1.4+
JAVA_OS=        native

PERL_CONFIGURE=	5.8.1+
CONFIGURE_ARGS=	J2SDK=${JAVA_HOME} </dev/null

MAN3=		Inline::Java.3 \
		Inline::Java::Callback.3

.include <bsd.port.mk>
