# New ports collection makefile for: FreePWING
# Version required:	1.1a
# Date created:		00/01/24
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	freepwing-1.1a
PKGNAME=	ja-freepwing-1.1a
CATEGORIES=	japanese textproc
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/misc/freepwing/freepwing/

MAINTAINER=	taoka@FreeBSD.org

RUN_DEPENDS=	gmake:${PORTSDIR}/devel/gmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/doc
USE_GMAKE=	yes
USE_PERL5=	yes

.include <bsd.port.mk>
