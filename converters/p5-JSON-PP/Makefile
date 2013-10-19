# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	JSON-PP
PORTVERSION=	2.27203
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MAKAMAKA
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON::XS compatible pure-Perl module

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
PLIST_SUB=	BIN_JSON_PP=""
.else
PLIST_SUB=	BIN_JSON_PP="@comment "
.endif

pre-patch:
	@${MV} ${WRKSRC}/bin/json_pp ${WRKSRC}/bin/p5json_pp
	@${REINPLACE_CMD} -e 's|bin/json_pp|bin/p5json_pp|' ${WRKSRC}/MANIFEST ${WRKSRC}/Makefile.PL

post-install:
.if ${PERL_LEVEL} < 501400
	${CP} -p ${STAGEDIR}${PREFIX}/bin/p5json_pp ${STAGEDIR}${PREFIX}/bin/json_pp
.endif

.include <bsd.port.post.mk>
