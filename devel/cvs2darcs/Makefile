# Created by: Oliver Braun <obraun@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cvs2darcs
PORTVERSION=	0.8
PORTREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	http://ab-initio.mit.edu/${PORTNAME}/

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Convert CVS module to darcs repository

LICENSE=	GPLv2

BUILD_DEPENDS=	cvs:devel/cvs \
		darcs:devel/hs-darcs \
		cvsps:devel/cvsps \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USES=		perl5
NO_BUILD=	yes
PLIST_FILES=	bin/cvs2darcs share/cvs2darcs/cvs_convert.pl \
		share/cvs2darcs/branch_detect.pl man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
