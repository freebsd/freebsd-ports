# New ports collection makefile for:	wu-ftpd
# Date created:		18 Oct 1994
# Whom:			torstenb
#
# $FreeBSD$
#
# REMINDER: to use ftpaccess(5) you need to specify -a in command line,
# it is changed from previous versions

PORTNAME=	wu-ftpd
PORTVERSION=	2.6.1
PORTREVISION=   9
CATEGORIES=	ftp
DIST_SUBDIR=    wu-ftpd
MASTER_SITES=	ftp://ftp.wu-ftpd.org/pub/wu-ftpd/
PATCH_SITES=    ftp://ftp.wu-ftpd.org/pub/wu-ftpd/patches/apply_to_2.6.1/

# Due to error pasv-port-allow-correction.patch copied locally as patch-ak
PATCHFILES=     ftpglob.patch \
		missing_format_strings.patch \
		nlst-shows-dirs.patch

MAINTAINER=	ache@FreeBSD.org

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-rfc931 --disable-pasvip --enable-opie \
		--enable-noop --disable-numericuid  --enable-nlst-dirs \
		--prefix=${PREFIX} --with-etc-dir=${PREFIX}/etc

MAN1=		ftpcount.1 ftpwho.1
MAN5=		ftpaccess.5 ftphosts.5 ftpconversions.5 xferlog.5 \
		ftpservers.5
MAN8=		ftpd.8 ftpshut.8 ftprestart.8 privatepw.8

USE_AUTOCONF=   yes

.include <bsd.port.mk>
