# New ports collection makefile for:	p5-IO-Compress-Base
# Date created:		2006-11-07
# Whom:			Thomas Abthorpe <thomas@goodking.ca>
#
# $FreeBSD$
#

PORTNAME=	IO-Compress-Base
PORTVERSION=	2.015
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Base Class for IO::Uncompress modules

PERL_CONFIGURE=	YES

MAN3=		IO::Uncompress::AnyUncompress.3 IO::Uncompress::Base.3 \
		File::GlobMapper.3 IO::Compress::Base.3

post-patch:
	@${REINPLACE_CMD} -e 's/5.009/5.666/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
