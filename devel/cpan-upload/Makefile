# New ports collection makefile for:	cpan-upload
# Date created:				Nov 30 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	cpan-upload
PORTVERSION=	2.2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/N/NE/NEILB/scripts/

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Script for uploading distributions to CPAN

BUILD_DEPENDS=	${SITE_PERL}/AppConfig/Std.pm:${PORTSDIR}/devel/p5-AppConfig-Std \
		${SITE_PERL}/Pod/Usage.pm:${PORTSDIR}/textproc/p5-Pod-Parser \
		${SITE_PERL}/Net/FTP.pm:${PORTSDIR}/net/p5-Net \
		${SITE_PERL}/HTTP/Request/Common.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	cpan-upload.1

.include <bsd.port.mk>
