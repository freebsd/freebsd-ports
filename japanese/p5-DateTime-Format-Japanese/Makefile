# Created by: Masahiro Teramoto <markun@onohara.to>
# $FreeBSD$

PORTNAME=	DateTime-Format-Japanese
PORTVERSION=	0.04000
CATEGORIES=	japanese devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DMAKI

MAINTAINER=	markun@onohara.to
COMMENT=	A Japanese DateTime Formatter

BUILD_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Calendar-Japanese>=0.05:${PORTSDIR}/devel/p5-DateTime-Calendar-Japanese \
		ja-p5-DateTime-Calendar-Japanese-Era>=0.08000:${PORTSDIR}/japanese/p5-DateTime-Calendar-Japanese-Era \
		p5-DateTime-Format-Builder>=0:${PORTSDIR}/devel/p5-DateTime-Format-Builder \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		DateTime::Format::Japanese.3 \
		DateTime::Format::Japanese::Common.3 \
		DateTime::Format::Japanese::Traditional.3

NO_STAGE=	yes
.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.include <bsd.port.post.mk>
