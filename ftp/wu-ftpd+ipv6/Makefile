# New ports collection makefile for:	wu-ftpd+ipv6
# Date created:		30 Aug 2002
# Whom:			sumikawa
#
# $FreeBSD$
#
# REMINDER: to use ftpaccess(5) you need to specify -a in command line,
# it is changed from previous versions

PORTNAME=	wu-ftpd+ipv6
PORTVERSION=	2.6.2
PORTREVISION=	7
CATEGORIES=	ftp ipv6
MASTER_SITES=	ftp://ftp.wu-ftpd.org/pub/wu-ftpd/
DISTNAME=	wu-ftpd-${PORTVERSION}

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	wu-ftpd-262-v6-20040130.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	A replacement ftp server for Un*x systems

CONFLICTS=	wu-ftpd-[0-9]* heimdal-[0-9]*

USE_AUTOCONF_VER=	213
CONFIGURE_ARGS=	--enable-rfc931 --disable-pasvip --enable-opie \
		--enable-noop --disable-numericuid  --enable-nlst-dirs \
		--enable-ipv6 \
		--prefix=${PREFIX} --with-etc-dir=${PREFIX}/etc

MAKE_ENV+=	WARNINGS=-DSPT_TYPE=SPT_BUILTIN

MAN1=		ftpcount.1 ftpwho.1
MAN5=		ftpaccess.5 ftphosts.5 ftpconversions.5 xferlog.5 \
		ftpservers.5
MAN8=		ftpd.8 ftpshut.8 ftprestart.8 privatepw.8

.include <bsd.port.mk>
