# New ports collection makefile for:	nethirc
# Date created:		15 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	nethirc
PORTVERSION=	0.04
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.nog.net/pub/tony/nethirc/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Perl-based irc client that uses Net::IRC

.include <bsd.port.pre.mk>
RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/IRC.pm:${PORTSDIR}/irc/p5-IRC

NO_BUILD=	yes
USE_PERL5=	yes
MAN1=		nethirc.1 nhirc.1

do-install:
	(cd ${WRKSRC} && ${SH} install.sh ${PREFIX})

.include <bsd.port.post.mk>
