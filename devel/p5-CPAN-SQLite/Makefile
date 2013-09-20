# Created by: Christopher Boumenot <boumenot@gmail.com>
# $FreeBSD$

PORTNAME=	CPAN-SQLite
PORTVERSION=	0.199
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RKOBES
PKGNAMEPREFIX=	p5-

MAINTAINER=	eg@fbsd.lt
COMMENT=	Search CPAN using a SQLite database

BUILD_DEPENDS=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite	\
		p5-File-HomeDir>=0:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-CPAN-DistnameInfo>=0:${PORTSDIR}/devel/p5-CPAN-DistnameInfo \
		p5-IO-Zlib>=0:${PORTSDIR}/archivers/p5-IO-Zlib \
		p5-Archive-Tar>=0:${PORTSDIR}/archivers/p5-Archive-Tar \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-PathTools>=0:${PORTSDIR}/devel/p5-PathTools
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=	cpandb.1
MAN3=	CPAN::SQLite::Index.3 \
	CPAN::SQLite::META.3 \
	CPAN::SQLite.3 \
	CPAN::SQLite::State.3 \
	CPAN::SQLite::DBI::Search.3 \
	CPAN::SQLite::DBI::Index.3 \
	CPAN::SQLite::DBI.3 \
	CPAN::SQLite::Util.3 \
	CPAN::SQLite::Populate.3 \
	CPAN::SQLite::Info.3 \
	CPAN::SQLite::Search.3

NO_STAGE=	yes
.include <bsd.port.mk>
