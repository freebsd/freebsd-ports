# New ports collection makefile for:	DBD::InterBase
# Date created:		15 Oct 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	DBD-InterBase
PORTVERSION=	0.40
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
LIB_DEPENDS=	gds:${PORTSDIR}/databases/firebird
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

post-patch:
		@${PERL} -pi -e 's,%%IB_BASE%%,${PREFIX}/firebird,g' \
			${WRKSRC}/Makefile.PL

MAN3=		Bundle::DBD::InterBase.3 DBD::InterBase.3 DBD::InterBase::FAQ.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
