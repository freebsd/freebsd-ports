# New ports collection makefile for:	orca
# Date created:				18 February 2003
# Whom:					jsellens
#
# $FreeBSD$
#

PORTNAME=	orca
PORTVERSION=	0.27b3
CATEGORIES=	graphics
MASTER_SITES=	http://www.orcaware.com/orca/pub/

MAINTAINER=	jsellens@generalconcepts.com
COMMENT=	Tool for plotting arbitrary data from text files onto a Web server

# needs some happy Perl modules
# I think Data::Dumper is installed as part of the FreeBSD base install
# How can I test for a version of one of these? e.g. Storable.pm should
# be >= version 2.05, p5-TimeDate >=1.40
BUILD_DEPENDS=	\
		${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/Math/Interpolate.pm:${PORTSDIR}/math/p5-Math-Interpolate \
		${SITE_PERL}/${PERL_ARCH}/RRDs.pm:${PORTSDIR}/net/rrdtool \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-html-dir=${PREFIX}/www/data/orca

MAN1=		orca.1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
