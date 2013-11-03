# Created by: Zach Thompson <hideo@lastamericanempire.com>
# $FreeBSD$

PORTNAME=	Oryx
PORTVERSION=	0.24
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	XML/RHUNDT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Meta-Model Driven Object Persistance with Multiple Inheritance

BUILD_DEPENDS=	p5-SQL-Abstract>=0:${PORTSDIR}/databases/p5-SQL-Abstract \
		p5-DBM-Deep>=0:${PORTSDIR}/databases/p5-DBM-Deep \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \
		p5-Class-Date>=0:${PORTSDIR}/devel/p5-Class-Date \
		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Ima-DBI>=0:${PORTSDIR}/databases/p5-Ima-DBI \
		p5-Data-Types>=0:${PORTSDIR}/devel/p5-Data-Types \
		p5-Class-Observable>=0:${PORTSDIR}/devel/p5-Class-Observable
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-XML-DOM-Lite>0:${PORTSDIR}/textproc/p5-XML-DOM-Lite \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
