# New ports collection makefile for:	databases/p5-Rose-DB-Object
# Date created:				09 June 2006
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	Rose-DB-Object
PORTVERSION=	0.7950
PORTEPOCH=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extensible, high performance RDBMS-OO mapper

BUILD_DEPENDS=	p5-Bit-Vector>=0:${PORTSDIR}/math/p5-Bit-Vector \
		p5-Clone>=0.29:${PORTSDIR}/devel/p5-Clone \
		p5-DBI>=1.400:${PORTSDIR}/databases/p5-DBI \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Rose-DB>=0.763,1:${PORTSDIR}/databases/p5-Rose-DB \
		p5-Rose-DateTime>=0.532,1:${PORTSDIR}/devel/p5-Rose-DateTime \
		p5-Rose-Object>=0.854:${PORTSDIR}/devel/p5-Rose-Object \
		p5-Time-Clock>=1:${PORTSDIR}/devel/p5-Time-Clock
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

.include <bsd.port.options.mk>

MAN3=	Rose::DB::Object.3 \
	Rose::DB::Object::Cached.3 \
	Rose::DB::Object::ConventionManager.3 \
	Rose::DB::Object::ConventionManager::Null.3 \
	Rose::DB::Object::Helpers.3 \
	Rose::DB::Object::Iterator.3 \
	Rose::DB::Object::Loader.3 \
	Rose::DB::Object::MakeMethods::BigNum.3 \
	Rose::DB::Object::MakeMethods::Date.3 \
	Rose::DB::Object::MakeMethods::Generic.3 \
	Rose::DB::Object::MakeMethods::Pg.3 \
	Rose::DB::Object::MakeMethods::Std.3 \
	Rose::DB::Object::MakeMethods::Time.3 \
	Rose::DB::Object::Manager.3 \
	Rose::DB::Object::Metadata.3 \
	Rose::DB::Object::Metadata::Column.3 \
	Rose::DB::Object::Metadata::Column::Array.3 \
	Rose::DB::Object::Metadata::Column::BigInt.3 \
	Rose::DB::Object::Metadata::Column::BigSerial.3 \
	Rose::DB::Object::Metadata::Column::Bitfield.3 \
	Rose::DB::Object::Metadata::Column::Blob.3 \
	Rose::DB::Object::Metadata::Column::Boolean.3 \
	Rose::DB::Object::Metadata::Column::Character.3 \
	Rose::DB::Object::Metadata::Column::Date.3 \
	Rose::DB::Object::Metadata::Column::Datetime.3 \
	Rose::DB::Object::Metadata::Column::DatetimeYearToFraction.3 \
	Rose::DB::Object::Metadata::Column::DatetimeYearToFraction1.3 \
	Rose::DB::Object::Metadata::Column::DatetimeYearToFraction2.3 \
	Rose::DB::Object::Metadata::Column::DatetimeYearToFraction3.3 \
	Rose::DB::Object::Metadata::Column::DatetimeYearToFraction4.3 \
	Rose::DB::Object::Metadata::Column::DatetimeYearToFraction5.3 \
	Rose::DB::Object::Metadata::Column::DatetimeYearToMinute.3 \
	Rose::DB::Object::Metadata::Column::DatetimeYearToMonth.3 \
	Rose::DB::Object::Metadata::Column::DatetimeYearToSecond.3 \
	Rose::DB::Object::Metadata::Column::Decimal.3 \
	Rose::DB::Object::Metadata::Column::DoublePrecision.3 \
	Rose::DB::Object::Metadata::Column::Enum.3 \
	Rose::DB::Object::Metadata::Column::Epoch.3 \
	Rose::DB::Object::Metadata::Column::Epoch::HiRes.3 \
	Rose::DB::Object::Metadata::Column::Float.3 \
	Rose::DB::Object::Metadata::Column::Integer.3 \
	Rose::DB::Object::Metadata::Column::Interval.3 \
	Rose::DB::Object::Metadata::Column::Numeric.3 \
	Rose::DB::Object::Metadata::Column::Pg::Bytea.3 \
	Rose::DB::Object::Metadata::Column::Pg::Chkpass.3 \
	Rose::DB::Object::Metadata::Column::Scalar.3 \
	Rose::DB::Object::Metadata::Column::Serial.3 \
	Rose::DB::Object::Metadata::Column::Set.3 \
	Rose::DB::Object::Metadata::Column::Text.3 \
	Rose::DB::Object::Metadata::Column::Time.3 \
	Rose::DB::Object::Metadata::Column::Timestamp.3 \
	Rose::DB::Object::Metadata::Column::TimestampWithTimeZone.3 \
	Rose::DB::Object::Metadata::Column::Varchar.3 \
	Rose::DB::Object::Metadata::ForeignKey.3 \
	Rose::DB::Object::Metadata::PrimaryKey.3 \
	Rose::DB::Object::Metadata::Relationship.3 \
	Rose::DB::Object::Metadata::Relationship::ManyToMany.3 \
	Rose::DB::Object::Metadata::Relationship::ManyToOne.3 \
	Rose::DB::Object::Metadata::Relationship::OneToMany.3 \
	Rose::DB::Object::Metadata::Relationship::OneToOne.3 \
	Rose::DB::Object::Metadata::UniqueKey.3 \
	Rose::DB::Object::MixIn.3 \
	Rose::DB::Object::QueryBuilder.3 \
	Rose::DB::Object::Std.3 \
	Rose::DB::Object::Std::Cached.3 \
	Rose::DB::Object::Std::Metadata.3 \
	Rose::DB::Object::Tutorial.3 \
	Rose::DB::Object::Util.3

.include <bsd.port.mk>
