# New ports collection makefile for:	orca
# Date created:				18 February 2003
# Whom:					jsellens
#
# $FreeBSD$
#

PORTNAME=	orca
PORTVERSION=	0.27
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.orcaware.com/orca/pub/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for plotting arbitrary data from text files onto a Web server

BUILD_DEPENDS=	\
		${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/Math/Interpolate.pm:${PORTSDIR}/math/p5-Math-Interpolate \
		${SITE_PERL}/${PERL_ARCH}/RRDs.pm:${PORTSDIR}/databases/rrdtool

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-html-dir=${PREFIX}/www/data/orca
USE_PERL5=	yes

MAN1=		orca.1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
