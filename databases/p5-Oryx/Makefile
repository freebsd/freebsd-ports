# New ports collection makefile for:	databases/p5-Oryx
# Date created:				18 February 2006
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	Oryx
PORTVERSION=	0.23
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML/RHUNDT
PKGNAMEPREFIX=	p5-

MAINTAINER= 	hideo@lastamericanempire.com
COMMENT=	Meta-Model Driven Object Persistance with Multiple Inheritance

BUILD_DEPENDS=	${SITE_PERL}/SQL/Abstract.pm:${PORTSDIR}/databases/p5-SQL-Abstract \
		${SITE_PERL}/Module/Pluggable.pm:${PORTSDIR}/devel/p5-Module-Pluggable \
		${SITE_PERL}/DBM/Deep.pm:${PORTSDIR}/databases/p5-DBM-Deep \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML \
		${SITE_PERL}/${PERL_ARCH}/Class/Date.pm:${PORTSDIR}/devel/p5-Class-Date \
		${SITE_PERL}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		${SITE_PERL}/Ima/DBI.pm:${PORTSDIR}/databases/p5-Ima-DBI \
		${SITE_PERL}/Data/Types.pm:${PORTSDIR}/devel/p5-Data-Types \
		${SITE_PERL}/Class/Observable.pm:${PORTSDIR}/devel/p5-Class-Observable \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=   Oryx.3 Oryx::Association.3 Oryx::Association::Array.3 Oryx::Attribute.3 \
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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
