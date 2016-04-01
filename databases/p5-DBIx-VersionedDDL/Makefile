# Created by: Alan Snelson <Alan@Wave2.org>
# $FreeBSD$

PORTNAME=	DBIx-VersionedDDL
PORTVERSION=	0.17
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	Alan@Wave2.org
COMMENT=	Upgrade and downgrade database schemas to a specified version

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBD-SQLite>=1.31:databases/p5-DBD-SQLite \
		p5-Moose>=1.21:devel/p5-Moose \
		p5-Text-CSV>=1.20:textproc/p5-Text-CSV \
		p5-MooseX-Attribute-ENV>=0.01:devel/p5-MooseX-Attribute-ENV \
		p5-MooseX-Object-Pluggable>=0:devel/p5-MooseX-Object-Pluggable
RUN_DEPENDS=	p5-DBD-SQLite>=1.31:databases/p5-DBD-SQLite \
		p5-Moose>=1.21:devel/p5-Moose \
		p5-Text-CSV>=1.20:textproc/p5-Text-CSV \
		p5-MooseX-Attribute-ENV>=0.01:devel/p5-MooseX-Attribute-ENV \
		p5-MooseX-Object-Pluggable>=0:devel/p5-MooseX-Object-Pluggable

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
