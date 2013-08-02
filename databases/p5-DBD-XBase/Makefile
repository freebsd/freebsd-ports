# Created by: Ilia Chipitsine <ilia@jane.cgu.chel.su>
# $FreeBSD$

PORTNAME=	DBD-XBase
PORTVERSION=	1.05
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provides access to XBase (dBase, Fox*) database files through DBI

BUILD_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI

USES=		perl5
USE_PERL5=	configure

MAN1=		dbfdump.1 indexdump.1
MAN3=		DBD::XBase.3 \
		XBase.3 \
		XBase::Base.3 \
		XBase::FAQ.3 \
		XBase::Index.3 \
		XBase::Memo.3 \
		XBase::SDBM.3

.include <bsd.port.mk>
