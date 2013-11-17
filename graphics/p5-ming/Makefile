# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	ming
PORTREVISION=	0
CATEGORIES=	graphics perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl5 module for Ming which allows you to create Flash 4/5 movies

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

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

.include <bsd.port.options.mk>

post-install:
	${SED} -i '' 's|^${STAGEDIR}||' ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/SWF/.packlist
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${INSTALL_WRKSRC}/examples/ && ${INSTALL_DATA} *.cgi ${STAGEDIR}${EXAMPLESDIR}/
.endif

.include "${MASTERDIR}/Makefile"
