# New ports collection makefile for: FreePWING
# Version required:	1.2beta2
# Date created:		00/01/24
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	freepwing-1.2beta2
PKGNAME=	ja-freepwing-1.2.b2
CATEGORIES=	japanese textproc
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/misc/freepwing/freepwing/ \
		ftp://ftp.sra.co.jp/pub/misc/freepwing/freepwing/beta/

MAINTAINER=	taoka@FreeBSD.org

RUN_DEPENDS=	gmake:${PORTSDIR}/devel/gmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/doc
USE_GMAKE=	yes
USE_PERL5=	yes

.include <bsd.port.mk>
