# New ports collection makefile for:	Text::Iconv
# Date created:		26 Dec 2000
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Text-Iconv
PORTVERSION=	1.4
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Perl interface to iconv() codeset conversion function

USE_ICONV=	yes

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	INC="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -liconv"

MAN3=		Text::Iconv.3

.include <bsd.port.mk>
