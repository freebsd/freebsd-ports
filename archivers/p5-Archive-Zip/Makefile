# New ports collection makefile for:	Archive-Zip
# Date created:				Mon Jan  1 09:33:13 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Archive-Zip
PORTVERSION=	1.05
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Archive
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@lansing.dk

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Archive::Zip.3 Archive::Zip::Tree.3 Archive::Zip::FAQ.3 Archive::Zip::MemberRead.3

.include <bsd.port.mk>

.if ${OSVERSION} < 500000 && !exists(${SITE_PERL}/File/Spec.pm)
BUILD_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
RUN_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
.endif
