# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-FTPSSL
PORTVERSION=	0.31
CATEGORIES=	ftp perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	FTP over SSL/TLS class

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-IO-Socket-SSL>=1.26:security/p5-IO-Socket-SSL \
		p5-Net-SSLeay>=0:security/p5-Net-SSLeay
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

# Avoid interactive prompt
post-patch:
	@${REINPLACE_CMD} -e '/prompt/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
