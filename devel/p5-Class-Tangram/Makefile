# New ports collection makefile for:	Class-Tangram
# Date created:	   08 April 2002
# Whom:		   Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-Tangram
PORTVERSION=	1.54
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Create constructors, accessor, update methods for objects from Tangram

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Set/Object.pm:${PORTSDIR}/devel/p5-Set-Object \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/Tangram.pm:${PORTSDIR}/databases/p5-Tangram
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::Tangram.3 Class::Tangram::Containers.3 \
		Class::Tangram::Generator.3

post-patch:
		@${PERL} -pi -e 's/\@/\\@/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
