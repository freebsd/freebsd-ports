# Created by: Oliver Braun <obraun@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cvs2darcs
PORTVERSION=	0.8
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	http://ab-initio.mit.edu/${PORTNAME}/

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Convert CVS module to darcs repository

LICENSE=	GPLv2

BUILD_DEPENDS=	cvs:${PORTSDIR}/devel/cvs \
		darcs:${PORTSDIR}/devel/hs-darcs \
		cvsps:${PORTSDIR}/devel/cvsps \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USES=		perl5
NO_BUILD=	yes
MAN1=	cvs2darcs.1
PLIST_FILES=	bin/cvs2darcs share/cvs2darcs/cvs_convert.pl \
		share/cvs2darcs/branch_detect.pl
PLIST_DIRS=	share/cvs2darcs

NO_STAGE=	yes
.include <bsd.port.mk>
