# New ports collection makefile for:	cvs+ipv6
# Date created:	Tue Jul 23 11:24:24 JST 2002
# Whom:		sumikawa
#
# $FreeBSD$
#

PORTNAME=	cvs+ipv6
PORTVERSION=	1.11.1p1
CATEGORIES=	devel ipv6
MASTER_SITES=	http://ftp.cvshome.org/cvs-1.11.1/
DISTNAME=	cvs-${PORTVERSION}

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	cvs-1.11.1p1-v6-20011105a.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	sumikawa@FreeBSD.org

GNU_CONFIGURE=	yes
#USE_GMAKE=	yes
CONFIGURE_ARGS=	--enable-ipv6

MAN1=		cvs.1
MAN5=		cvs.5
MAN8=		cvsbug.8

CVS_SITE?=	:pserver:anoncvs@anoncvs.FreeBSD.org:/home/ncvs
CVS_VER?=	v1_11_1p1

post-patch:
	@${CP} ${FILESDIR}/missing ${WRKSRC}

.include <bsd.port.mk>
