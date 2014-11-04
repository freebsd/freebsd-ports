# Created by: Frank Wall <fw@moov.de>
# $FreeBSD$

PORTNAME=	Sys-Virt
PORTVERSION=	1.1.1
PORTREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	fw@moov.de
COMMENT=	Perl bindings for libvirt

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-XML-XPath>=0:${PORTSDIR}/textproc/p5-XML-XPath
LIB_DEPENDS=	libvirt.so:${PORTSDIR}/devel/libvirt
RUN_DEPENDS=	p5-XML-XPath>=0:${PORTSDIR}/textproc/p5-XML-XPath
TEST_DEPENDS=	p5-CPAN-Changes>=0:${PORTSDIR}/devel/p5-CPAN-Changes \
		p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage

USES=		perl5 pkgconfig
USE_PERL5=	configure
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '1 s|/usr/bin/perl|${PERL}|' ${WRKSRC}/examples/*.pl

post-install:
	${STRIP_CMD} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Sys/Virt/Virt.so
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/*.pl ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
