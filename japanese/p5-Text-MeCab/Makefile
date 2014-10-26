# Created by: TAOKA Fumiyoshi <fmysh@iijmio-mail.jp>
# $FreeBSD$

PORTNAME=		Text-MeCab
PORTVERSION=		0.20009
CATEGORIES=		japanese textproc perl5
MASTER_SITES=		CPAN

MAINTAINER=		fmysh@iijmio-mail.jp
COMMENT=		Alternate Interface To libmecab

BUILD_DEPENDS=		p5-Devel-PPPort>=3.19:${PORTSDIR}/devel/p5-Devel-PPPort \
			p5-ExtUtils-ParseXS>=2.21:${PORTSDIR}/devel/p5-ExtUtils-ParseXS \
			p5-Test-Simple>=0.84:${PORTSDIR}/devel/p5-Test-Simple \
			p5-Test-Requires>0:${PORTSDIR}/devel/p5-Test-Requires
RUN_DEPENDS=		p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
			p5-Encode>0:${PORTSDIR}/converters/p5-Encode\
			p5-XSLoader>0.1:${PORTSDIR}/devel/p5-XSLoader
LIB_DEPENDS=		libmecab.so:${PORTSDIR}/japanese/mecab

MAKE_JOBS_UNSAFE=	yes

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	</dev/null

# dictionary encoding (euc-jp, shift_jis, utf-8)
ENCODING?=	euc-jp

post-patch:
	@${REINPLACE_CMD} -e "/default_encoding = /s/euc-jp/${ENCODING}/" \
		${WRKSRC}/tools/probe_mecab.pl

post-configure:
	@${REINPLACE_CMD} -e "/^LD = /s/cc/cc -pthread/" \
		${WRKSRC}/Makefile

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.if ${PERL_VER} >= 5.18
BROKEN=		Does not build with Perl 5.18 or above
.endif

.include <bsd.port.post.mk>
