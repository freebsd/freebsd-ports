# New ports collection makefile for:	p5-DBD-XBase
# Date created:				10th September 2000
# Whom:					Ilia Chipitsine <ilia@jane.cgu.chel.su>
#
# $FreeBSD$

PORTNAME=	DBD-XBase
PORTVERSION=	0.234
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	ilia@cgu.chel.su
COMMENT=	Provides access to XBase (dBase, Fox*) database files through DBI

PERL_CONFIGURE=	yes

MAN1=		dbfdump.1 indexdump.1
MAN3=		DBD::XBase.3 \
		XBase.3 \
		XBase::Base.3 \
		XBase::FAQ.3 \
		XBase::Index.3 \
		XBase::Memo.3 \
		XBase::SDBM.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.endif

.include <bsd.port.post.mk>
