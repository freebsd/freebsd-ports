# New ports collection makefile for:	p5-DBD-XBase
# Date created:				10th September 2000
# Whom:					Ilia Chipitsine <ilia@jane.cgu.chel.su>
#
# $FreeBSD$

PORTNAME=	DBD-XBase
PORTVERSION=	0.161
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	ilia@cgu.chel.su

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI

PERL_CONFIGURE=	yes

GZIP=		-9

MAN1=		dbfdump.1 indexdump.1

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		XBase::FAQ.3 XBase::Memo.3 XBase::Index.3 XBase.3 \
		DBD::XBase.3 XBase::Base.3

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/dbfdump ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/indexdump ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/blib/man1/dbfdump.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/blib/man1/indexdump.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
