# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	XML-Pastor
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Generate Perl classes with XML bindings from a W3C XSD schema

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>=0:devel/p5-Class-Data-Inheritable \
		p5-Data-HashArray>=0:devel/p5-Data-HashArray \
		p5-File-chdir>=0:devel/p5-File-chdir \
		p5-URI>=0:net/p5-URI \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
