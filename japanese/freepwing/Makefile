# New ports collection makefile for: FreePWING
# Date created:		00/01/24
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freepwing
PORTVERSION=	1.4.3
PORTREVISION=	1
CATEGORIES=	japanese textproc
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/misc/freepwing/ \
		ftp://ftp.sra.co.jp/pub/misc/freepwing/old/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	taoka@FreeBSD.org
COMMENT=	Free JIS X 4081 (subset of EPWING V1) Formatter

RUN_DEPENDS=	gmake:${PORTSDIR}/devel/gmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/doc
USE_GMAKE=	yes
USE_PERL5=	yes

.include <bsd.port.mk>
