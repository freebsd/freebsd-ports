# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	Text-ChaSen
PORTVERSION=	1.03
PORTREVISION=	7
CATEGORIES=	japanese textproc perl5
MASTER_SITES=	OSDN/chasen-legacy
DISTNAME=	chasen-${CHASEN_VERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	ChaSen library module for Perl5

LIB_DEPENDS=	libchasen.so:japanese/chasen-base

DISTINFO_FILE=	${.CURDIR}/../chasen-base/distinfo

CHASEN_VERSION=	2.4.5

WRKSRC=		${WRKDIR}/chasen-${CHASEN_VERSION}/perl
USES=		perl5
USE_PERL5=	configure
CONFIGURE_ENV=	PREFIX="${PREFIX}"
DOCSDIR=	${PREFIX}/share/doc/chasen

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Text/ChaSen/ChaSen.so
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/README.perl

.include <bsd.port.post.mk>
