# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	MeCab
PORTVERSION=	0.995
CATEGORIES=	japanese textproc perl5
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	${PORTNAME:L}
DISTNAME=	${PORTNAME:L}-perl-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	MeCab library module for Perl5

LICENSE=	BSD GPLv2 LGPL21
LICENSE_COMB=	dual
LICENSE_FILE_BSD=	${WRKSRC}/BSD
LICENSE_FILE_GPLv2=	${WRKSRC}/GPL
LICENSE_FILE_LGPL21=	${WRKSRC}/LGPL

LIB_DEPENDS=	mecab:${PORTSDIR}/japanese/mecab

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	EXAMPLES
OPTIONSFILE=	${PORT_DBDIR}/ja-p5-${PORTNAME}/options

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.if ${PORT_OPTIONS:MEXAMPLES}
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test.pl ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
