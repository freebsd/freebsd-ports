# Created by: Leo Vandewoestijne <freebsd@dns.company>
# $FreeBSD$

PORTNAME=	p5-DSC
PORTVERSION=	2.04
CATEGORIES=	dns perl5
MASTER_SITES=	https://www.dns-oarc.net/files/dsc/ \
		https://dns.company/downloads/dsc/

MAINTAINER=	freebsd@dns.company
COMMENT=	DNS Statistics Presenter Perl Library

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	ploticus>=2.40:math/ploticus				\
		p5-CGI-Untaint>=1.26:www/p5-CGI-Untaint			\
		p5-File-NFSLock>=1.21:devel/p5-File-NFSLock		\
		p5-Hash-Merge>=0.299:textproc/p5-Hash-Merge		\
		p5-IP-Country>=2.28:net/p5-IP-Country			\
		p5-Math-Calc-Units>=1.07:math/p5-Math-Calc-Units	\
		p5-Net-DNS>=1.15:dns/p5-Net-DNS				\
		p5-Text-Template>=1.51:textproc/p5-Text-Template	\
		p5-Any-URI-Escape>=0.01:www/p5-Any-URI-Escape		\
		p5-URI>=1.73:net/p5-URI					\
		p5-XML-Simple>=2.24:textproc/p5-XML-Simple


NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure patch

.include <bsd.port.mk>
