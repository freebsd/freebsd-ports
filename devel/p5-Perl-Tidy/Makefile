# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Perl-Tidy
PORTVERSION=	20181118
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Indents and reformats Perl scripts to make them easier to read

LICENSE=	GPLv2

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|#EXE_FILES|EXE_FILES|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
