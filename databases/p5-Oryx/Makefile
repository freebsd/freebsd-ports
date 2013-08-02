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
		p5-Class-Observable>=0:${PORTSDIR}/devel/p5-Class-Observable \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-XML-DOM-Lite>0:${PORTSDIR}/textproc/p5-XML-DOM-Lite \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite

USES=		perl5
USE_PERL5=	configure

MAN3=	Oryx.3 Oryx::Association.3 Oryx::Association::Array.3 Oryx::Attribute.3 \
	Oryx::Class.3 Oryx::DBI.3 Oryx::DBI::Util.3 Oryx::DBM.3 Oryx::Manual::Guts.3 \
	Oryx::MetaClass.3 Oryx::Parent.3 Oryx::Schema.3 Oryx::Value.3 \
	Oryx::DBI::Association::Hash.3 Oryx::Value::String.3 \
	Oryx::DBI::Util::Pg.3 Oryx::DBI::Attribute.3 Oryx::DBI::Association.3 \
	Oryx::Value::Oid.3 Oryx::DBI::Util::mysql.3 Oryx::Value::Binary.3 \
	Oryx::DBI::Association::Array.3 Oryx::Association::Hash.3 \
	Oryx::Value::Integer.3 Oryx::DBM::Association::Array.3 \
	Oryx::DBM::Association::Reference.3 Oryx::DBI::Class.3 \
	Oryx::Value::Boolean.3 Oryx::Value::Float.3 Oryx::Value::Complex.3 \
	Oryx::DBI::Util::Generic.3 Oryx::DBM::Association::Hash.3 \
	Oryx::DBM::Attribute.3 Oryx::DBI::Association::Reference.3 \
	Oryx::DBM::Parent.3 Oryx::Value::DateTime.3 Oryx::DBI::Util::SQLite.3 \
	Oryx::DBM::Association.3 Oryx::DBM::Class.3 Oryx::DBI::Parent.3 \
	Oryx::Association::Reference.3 Oryx::DBM::Util.3 Oryx::Value::Text.3

.include <bsd.port.mk>
