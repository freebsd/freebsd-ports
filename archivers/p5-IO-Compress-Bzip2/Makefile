# New ports collection makefile for:	p5-IO-Compress-Bzip2
# Date created:		2007-01-16
# Whom:			Thomas Abthorpe <thomas@goodking.ca>
#
# $FreeBSD$
#

PORTNAME=	IO-Compress-Bzip2
PORTVERSION=	2.005
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IO
PKGNAMEPREFIX=	p5-

MAINTAINER=	thomas@goodking.ca
COMMENT=	An interface to allow writing bzip2 compressed data to files or buffer

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Compress/Raw/Bzip2.pm:${PORTSDIR}/archivers/p5-Compress-Raw-Bzip2 \
		${SITE_PERL}/IO/Compress/Base.pm:${PORTSDIR}/archivers/p5-IO-Compress-Base:${PORTSDIR}/archivers/p5-IO-Compress-Base
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		IO::Compress::Bzip2.3 IO::Uncompress::Bunzip2.3

.include <bsd.port.mk>
