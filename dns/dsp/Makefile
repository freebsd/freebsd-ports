# Created by: Leo Vandewoestijne <freebsd@dns.company>
# $FreeBSD$

PORTNAME=	dsp
PORTVERSION=	2.0.1
CATEGORIES=	dns
MASTER_SITES=	https://www.dns-oarc.net/files/dsc/ \
		https://dns.company/files/dsc/

MAINTAINER=	freebsd@dns.company
COMMENT=	Tool used for collecting and exploring statistics from DNS servers

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	p5-Proc-PID-File>=1.28:devel/p5-Proc-PID-File		\
		p5-XML-Simple>=2.24:textproc/p5-XML-Simple		\
		p5-App-DSC-DataTool>=0.03:dns/p5-App-DSC-DataTool	\
		p5-DSC>=2.04:dns/p5-DSC					\
		p5-CGI>=4.38:www/p5-CGI					\
		p5-Switch>=2.17:lang/p5-Switch				\
		p5-File-Copy-Link>=0.140:devel/p5-File-Copy-Link

RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes

USES=		gmake perl5
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
