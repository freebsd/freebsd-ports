# New ports collection makefile for:	Class-DBI
# Date created:		15 Dec 2001
# Whom:			Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-DBI
PORTVERSION=	0.89
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Carp/Assert.pm:${PORTSDIR}/devel/p5-Carp-Assert \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/DBD/CSV.pm:${PORTSDIR}/databases/p5-DBD-CSV \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Ima/DBI.pm:${PORTSDIR}/databases/p5-Ima-DBI \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/protected.pm:${PORTSDIR}/devel/p5-Class-Fields \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Class/Trigger.pm:${PORTSDIR}/devel/p5-Class-Trigger
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Class::DBI.3

post-configure:
# dirty hack to deceive irritable pod2man
	@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' ${WRKSRC}/Makefile

.include <bsd.port.mk>
