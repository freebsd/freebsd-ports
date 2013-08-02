# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	Visio
PORTVERSION=	1.010
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension manipulating XML based Visio files

BUILD_DEPENDS=	p5-Log-Log4perl>=0:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML

USES=		perl5
USE_PERL5=	configure

MAN3=		Visio.3 Visio::Hyperlink.3 Visio::Layout.3 Visio::Line.3 \
		Visio::Master.3 Visio::Page.3 Visio::PageProps.3 \
		Visio::PageSheet.3 Visio::Shape.3

.include <bsd.port.mk>
