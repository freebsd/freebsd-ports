# New ports collection makefile for:	cvs+ipv6
# Date created:	Tue Jul 23 11:24:24 JST 2002
# Whom:		sumikawa
#
# $FreeBSD$
#

PORTNAME=	cvs+ipv6
PORTVERSION=	1.11.2
CATEGORIES=	devel ipv6
MASTER_SITES=	http://ftp.cvshome.org/cvs-1.11.2/
#		${MASTER_SITE_GNU}
#MASTER_SITE_SUBDIR=	non-gnu/cvs
DISTNAME=	cvs-${PORTVERSION}

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	cvs-1.11.2-v6-20020709.diff.gz
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

replace:
.for f in cvs cvsbug
	${MV} /usr/bin/${f} /usr/bin/${f}.orig
	${CP} -p ${PREFIX}/bin/${f} /usr/bin/
.endfor

.include <bsd.port.mk>
