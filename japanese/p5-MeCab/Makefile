# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	MeCab
PORTVERSION=	0.996
PORTREVISION=	1
CATEGORIES=	japanese textproc perl5
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	${PORTNAME:tl}
DISTNAME=	${PORTNAME:tl}-perl-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	MeCab library module for Perl5

LICENSE=	BSD3CLAUSE GPLv2 LGPL21
LICENSE_COMB=	dual

LIB_DEPENDS=	libmecab.so:${PORTSDIR}/japanese/mecab

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	EXAMPLES
OPTIONSFILE=	${PORT_DBDIR}/ja-p5-${PORTNAME}/options

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

pre-install:
	${STRIP_CMD} ${WRKSRC}/blib/arch/auto/MeCab/MeCab.so

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test.pl ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
