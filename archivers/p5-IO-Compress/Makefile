# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	IO-Compress
PORTVERSION=	2.063
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PMQS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl5 compression modules (bzip2, deflate, gzip, zlib, zip)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Compress-Raw-Bzip2>=2.063:${PORTSDIR}/archivers/p5-Compress-Raw-Bzip2 \
		p5-Compress-Raw-Zlib>=2.063:${PORTSDIR}/archivers/p5-Compress-Raw-Zlib
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod

CONFLICTS=	p5-Compress-Zlib-2* p5-IO-Compress-Base-2* p5-IO-Compress-Zlib-2* p5-IO-Compress-Bzip2-2*

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 501600
PLIST_SUB+=	EXE_FILES="@comment "
.else
PLIST_SUB+=	EXE_FILES=""
.endif

post-patch:
.if ${PERL_LEVEL} >= 501600
	@${REINPLACE_CMD} -e '/EXE_FILES/d' ${WRKSRC}/Makefile.PL
.endif

.include <bsd.port.post.mk>
