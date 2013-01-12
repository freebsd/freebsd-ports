# $FreeBSD$

PORTNAME=	Dist-Metadata
PORTVERSION=	0.924
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for information about a perl module distribution

RUN_DEPENDS=	\
	p5-Archive-Zip>=1.30:${PORTSDIR}/archivers/p5-Archive-Zip \
	p5-CPAN-DistnameInfo>=0.12:${PORTSDIR}/devel/p5-CPAN-DistnameInfo \
	p5-CPAN-Meta>=2.1:${PORTSDIR}/devel/p5-CPAN-Meta \
	p5-File-Spec-Native>=1.002:${PORTSDIR}/devel/p5-File-Spec-Native \
	p5-Module-Metadata>0:${PORTSDIR}/devel/p5-Module-Metadata \
	p5-Path-Class>=0.24:${PORTSDIR}/devel/p5-Path-Class \
	p5-Try-Tiny>=0.09:${PORTSDIR}/lang/p5-Try-Tiny
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Fatal>0:${PORTSDIR}/devel/p5-Test-Fatal \
	p5-Test-MockObject>0:${PORTSDIR}/devel/p5-Test-MockObject \
	p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=	Dist::Metadata.3 \
	Dist::Metadata::Archive.3 \
	Dist::Metadata::Dir.3 \
	Dist::Metadata::Dist.3 \
	Dist::Metadata::Struct.3 \
	Dist::Metadata::Tar.3 \
	Dist::Metadata::Zip.3

.include <bsd.port.mk>
