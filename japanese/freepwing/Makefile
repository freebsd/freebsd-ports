# Created by: Satoshi TAOKA <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freepwing
PORTVERSION=	1.4.4
PORTREVISION=	2
CATEGORIES=	japanese textproc
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/misc/freepwing/old/1.4/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free JIS X 4081 (subset of EPWING V1) Formatter

RUN_DEPENDS=	gmake:devel/gmake

USES=		gmake perl5
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pkgdocdir=${DOCSDIR}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
