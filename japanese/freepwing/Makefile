# New ports collection makefile for: FreePWING
# Date created:		00/01/24
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freepwing
PORTVERSION=	1.4.4
CATEGORIES=	japanese textproc
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/misc/freepwing/ \
		ftp://ftp.sra.co.jp/pub/misc/freepwing/old/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free JIS X 4081 (subset of EPWING V1) Formatter

RUN_DEPENDS=	gmake:${PORTSDIR}/devel/gmake

USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-pkgdocdir=${DOCSDIR}

.include <bsd.port.mk>
