# Created by: autrijus@autrijus.org
# $FreeBSD$

PORTNAME=	VCP
PORTVERSION=	0.9.20050110
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AUTRIJUS
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	-autrijus
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-snapshot-${PORTVERSION:C/\.([^.]*)$/-\1/}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Tool for copying files between various SCM repositories

BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser \
		p5-XML-AutoWriter>=0:textproc/p5-XML-AutoWriter \
		p5-Text-Diff>=0:textproc/p5-Text-Diff \
		p5-IPC-Run3>=0:devel/p5-IPC-Run3 \
		p5-PodToHTML>=0:www/p5-PodToHTML \
		p5-Regexp-Shellish>=0:devel/p5-Regexp-Shellish \
		p5-BFD>=0:devel/p5-BFD \
		p5-Text-Table>=0:textproc/p5-Text-Table
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-patch:
	${FIND} ${WRKSRC} -name "*.orig" -a -exec ${RM} -f {} \;

.include <bsd.port.mk>
