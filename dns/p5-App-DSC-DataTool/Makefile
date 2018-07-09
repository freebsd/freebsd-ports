# Created by: Leo Vandewoestijne <freebsd@dns.company>
# $FreeBSD$

PORTNAME=	p5-App-DSC-DataTool
PORTVERSION=	0.03
CATEGORIES=	dns perl5
MASTER_SITES=	https://www.dns-oarc.net/files/dsc/ \
		https://dns.company/downloads/dsc/

MAINTAINER=	freebsd@dns.company
COMMENT=	Tool for converting, exporting, merging and transforming DSC data

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${RUN_DEPENDS} \
		${TEST_DEPENDS}
RUN_DEPENDS=	p5-common-sense>=3:devel/p5-common-sense		\
		p5-IO-Socket-INET6>=1.31:net/p5-IO-Socket-INET6		\
		p5-IP-Country>=2.28:net/p5-IP-Country			\
		p5-Module-Find>=0.13:devel/p5-Module-Find		\
		p5-NetAddr-IP>=4.078:net-mgmt/p5-NetAddr-IP		\
		p5-Scalar-Util-Numeric>=0.40:devel/p5-Scalar-Util-Numeric \
		p5-Test-More-UTF8>=0.04:devel/p5-Test-More-UTF8		\
		p5-XML-LibXML-Simple>=0.93:textproc/p5-XML-LibXML-Simple \
		p5-YAML-Tiny>=1.69:textproc/p5-YAML-Tiny
TEST_DEPENDS=	p5-Test-CheckManifest>=0.9:devel/p5-Test-CheckManifest

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
