# Created by: Rong-En Fan <rafan@infor.org>
# $FreeBSD$

PORTNAME=	Encode
PORTVERSION=	2.88
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DANKOGAI
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provides interfaces between strings and the rest of the system

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502200
PLIST_SUB+=	OLD_PERL=""
.else
PLIST_SUB+=	OLD_PERL="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|bin/enc2xs||; s|bin/piconv||' ${WRKSRC}/Makefile.PL
.if ${PERL_LEVEL} >= 502200
	@${REINPLACE_CMD} -e 's|bin/encguess||' ${WRKSRC}/Makefile.PL
.endif

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Encode/ -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.post.mk>
