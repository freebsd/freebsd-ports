# Created by:	Frank Wall <fw@moov.de>
# $FreeBSD$

PORTNAME=	Sys-Virt
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	fw@moov.de
COMMENT=	Perl bindings for libvirt

BUILD_DEPENDS=	p5-XML-XPath>=0:${PORTSDIR}/textproc/p5-XML-XPath
LIB_DEPENDS=	virt.1001:${PORTSDIR}/devel/libvirt
RUN_DEPENDS=	p5-XML-XPath>=0:${PORTSDIR}/textproc/p5-XML-XPath
TEST_DEPENDS=	p5-CPAN-Changes>=0:${PORTSDIR}/devel/p5-CPAN-Changes \
		p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage

PERL_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

MAN3=		Sys::Virt.3 \
		Sys::Virt::Domain.3 \
		Sys::Virt::DomainSnapshot.3 \
		Sys::Virt::Error.3 \
		Sys::Virt::Event.3 \
		Sys::Virt::Interface.3 \
		Sys::Virt::NWFilter.3 \
		Sys::Virt::Network.3 \
		Sys::Virt::NodeDevice.3 \
		Sys::Virt::Secret.3 \
		Sys::Virt::StoragePool.3 \
		Sys::Virt::StorageVol.3 \
		Sys::Virt::Stream.3

PORTEXAMPLES=	*

.include <bsd.port.options.mk>

post-patch:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${REINPLACE_CMD} -e '1 s|/usr/bin/perl|${PERL}|' ${WRKSRC}/examples/*.pl
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/*.pl ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
