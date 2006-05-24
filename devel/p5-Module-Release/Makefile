# New ports collection makefile for:	release
# Date created:	   14 Mart 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Module-Release
PORTVERSION=	1.08
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/B/BD/BDFOY
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Upload files to CPAN and SourceForge

BUILD_DEPENDS=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp \
		${SITE_PERL}/Net/FTP.pm:${PORTSDIR}/net/p5-Net \
		${SITE_PERL}/ConfigReader/Simple.pm:${PORTSDIR}/devel/p5-ConfigReader-Simple \
		${SITE_PERL}/${PERL_ARCH}/Crypt/SSLeay.pm:${PORTSDIR}/security/p5-Crypt-SSLeay \
		${SITE_PERL}/HTTP/Message.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		release.1
MAN3=		Release.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	perl 5.8 or newer required. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
