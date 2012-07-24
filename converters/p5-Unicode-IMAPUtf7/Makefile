# New ports collection makefile for:	Unicode::IMAPUtf7
# Date created:				25 Jan 2002
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	Unicode-IMAPUtf7
PORTVERSION=	2.01
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Unicode/FABPOT
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl extension to deal with IMAP UTF-7

BUILD_DEPENDS=	p5-Unicode-String>=0:${PORTSDIR}/converters/p5-Unicode-String
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Unicode::IMAPUtf7.3

post-extract:	# breaks non-root build otherwise
	${CHMOD} u+x ${WRKSRC}
	${CHMOD} u+x ${WRKSRC}/t ${WRKSRC}/lib
	${CHMOD} u+x ${WRKSRC}/lib/Unicode

.include <bsd.port.mk>
