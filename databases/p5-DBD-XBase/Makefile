# New ports collection makefile for:	p5-DBD-XBase
# Date created:				10th September 2000
# Whom:					Ilia Chipitsine <ilia@jane.cgu.chel.su>
#
# $FreeBSD$

PORTNAME=	DBD-XBase
PORTVERSION=	0.241
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provides access to XBase (dBase, Fox*) database files through DBI

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI

PERL_CONFIGURE=	yes

MAN1=		dbfdump.1 indexdump.1
MAN3=		DBD::XBase.3 \
		XBase.3 \
		XBase::Base.3 \
		XBase::FAQ.3 \
		XBase::Index.3 \
		XBase::Memo.3 \
		XBase::SDBM.3

.include <bsd.port.mk>
