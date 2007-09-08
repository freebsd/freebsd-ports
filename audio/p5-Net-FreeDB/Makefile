# New ports collection makefile for:	p5-Net-FreeDB
# Date created:				September 29th, 2005
# Whom:	      				Peter Pentchev <roam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-FreeDB
PORTVERSION=	0.08
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/R/RO/ROAM
PKGNAMEPREFIX=	p5-

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Get the CDID of an audio CD and query the FreeDB servers

BUILD_DEPENDS=	${SITE_PERL}/CDDB/File.pm:${PORTSDIR}/audio/p5-CDDB-File \
		${SITE_PERL}/Net/Cmd.pm:${PORTSDIR}/net/p5-Net \
		${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::FreeDB.3

.include <bsd.port.mk>
