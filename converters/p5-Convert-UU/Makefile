# New ports collection makefile for:	p5-Convert-UU
# Version required:			0.04
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.8 1997/04/27 00:14:27 asami Exp $
#

DISTNAME=	Convert-UU-0.04
PKGNAME=	p5-Convert-UU-0.04
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Convert

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.004:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.004:${PORTSDIR}/lang/perl5

MAN1=		puuencode.1 puudecode.1
MAN3=		Convert::UU.3
MAN3PREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
