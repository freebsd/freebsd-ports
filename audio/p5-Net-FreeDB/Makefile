# New ports collection makefile for:	p5-Net-FreeDB
# Date created:				September 29th, 2005
# Whom:	      				Peter Pentchev <roam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-FreeDB
PORTVERSION=	0.06
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

PATCH_SITES=	${MASTER_SITE_LOCAL} \
		http://people.FreeBSD.org/~roam/ports/patches/net/
PATCH_SITE_SUBDIR=	roam/net
PATCHFILES=	Net-FreeDB-0.06-FreeBSD.patch

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Get the CDID of an audio CD and query the FreeDB servers

BUILD_DEPENDS=	${SITE_PERL}/CDDB/File.pm:${PORTSDIR}/audio/p5-CDDB-File \
		${SITE_PERL}/Net/Cmd.pm:${PORTSDIR}/net/p5-Net
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::FreeDB.3

.include <bsd.port.mk>
