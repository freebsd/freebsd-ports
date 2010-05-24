# New ports collection makefile for:	cvs2darcs
# Date created:				1 March 2007
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cvs2darcs
PORTVERSION=	0.8
CATEGORIES=	devel
MASTER_SITES=	http://ab-initio.mit.edu/${PORTNAME}/

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Convert CVS module to darcs repository

BUILD_DEPENDS=	darcs:${PORTSDIR}/devel/hs-darcs \
		cvsps:${PORTSDIR}/devel/cvsps \
		${SITE_PERL}/HTTP/Date.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_PERL5=	yes
NO_BUILD=	yes
MAN1=	cvs2darcs.1
PLIST_FILES=	bin/cvs2darcs share/cvs2darcs/cvs_convert.pl \
		share/cvs2darcs/branch_detect.pl
PLIST_DIRS=	share/cvs2darcs

.include <bsd.port.mk>
