# New ports collection makefile for:	p5-Net-FreeDB
# Date created:				September 29th, 2005
# Whom:	      				Peter Pentchev <roam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-FreeDB
PORTVERSION=	0.07
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/R/RO/ROAM
PKGNAMEPREFIX=	p5-

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Get the CDID of an audio CD and query the FreeDB servers

BUILD_DEPENDS=	${SITE_PERL}/CDDB/File.pm:${PORTSDIR}/audio/p5-CDDB-File \
		${SITE_PERL}/Net/Cmd.pm:${PORTSDIR}/net/p5-Net
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::FreeDB.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600 # inherited by p5-Authen-SASL
IGNORE=	requires at least Perl 5.6.  Please install lang/perl5.8 and try again
#EXTRA_PATCHES+=	${FILESDIR}/perl-5005.patch
.endif

.include <bsd.port.post.mk>
