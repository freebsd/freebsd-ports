# New ports collection makefile for:	Class-DBI
# Date created:		15 Dec 2001
# Whom:			Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-DBI
PORTVERSION=	0.96
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Simple Database Abstraction

BUILD_DEPENDS=	${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		${SITE_PERL}/Ima/DBI.pm:${PORTSDIR}/databases/p5-Ima-DBI \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/UNIVERSAL/moniker.pm:${PORTSDIR}/devel/p5-UNIVERSAL-moniker \
		${SITE_PERL}/${PERL_ARCH}/List/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		${SITE_PERL}/Class/Trigger.pm:${PORTSDIR}/devel/p5-Class-Trigger
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::DBI.3 Class::DBI::Column.3 Class::DBI::ColumnGrouper.3 \
		Class::DBI::Iterator.3 Class::DBI::Query.3 Class::DBI::Relationship.3

post-configure:
# dirty hack to deceive irritable pod2man
	@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' ${WRKSRC}/Makefile

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES=	${PATCHDIR}/5.005-lib::Class::DBI.pm ${PATCHDIR}/5.005-Makefile.PL

post-patch:
	@${FIND} ${WRKSRC} -name "*.pm" | ${XARGS} \
		${PERL} -pi -e 's/\buse warnings[^;]*;//g'
	@${FIND} ${WRKSRC} -name "*.orig" | ${XARGS} ${RM}
.endif
.endif

.include <bsd.port.post.mk>
