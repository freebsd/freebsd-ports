# New ports collection makefile for:	Sys::Virt
# Date created:		Nov 21 2011
# Whom:			Frank Wall <fw@moov.de>
#
# $FreeBSD$
#

PORTNAME=	Sys-Virt
PORTVERSION=	0.9.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	fw@moov.de
COMMENT=	Perl bindings for libvirt

BUILD_DEPENDS=	p5-XML-XPath>=0:${PORTSDIR}/textproc/p5-XML-XPath
LIB_DEPENDS=	virt:${PORTSDIR}/devel/libvirt
RUN_DEPENDS=	p5-XML-XPath>=0:${PORTSDIR}/textproc/p5-XML-XPath
TEST_DEPENDS=	p5-CPAN-Changes>=0:${PORTSDIR}/devel/p5-CPAN-Changes \
		p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage

PERL_CONFIGURE=	yes

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

.include <bsd.port.mk>
