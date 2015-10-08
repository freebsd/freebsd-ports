# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	ming
CATEGORIES=	graphics perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl5 module for Ming which allows you to create Flash 4/5 movies

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSE_GPL2
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	EXAMPLES

CONFIGURE_ARGS=	--enable-perl
INSTALL_WRKSRC=	${WRKSRC}/perl_ext
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VER}
PATCH_WRKSRC=	${WRKSRC}/perl_ext
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist
USES=		perl5

MASTERDIR=	${.CURDIR}/../../graphics/ming
SLAVEPORT=	p5

.include "${MASTERDIR}/Makefile"
