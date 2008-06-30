# New ports collection makefile for:	SJ3
# Date created:		18 Aug 1998
# Whom:			Hidekazu Kuroki <hidekazu@cs.titech.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	sj3
PORTVERSION=	2.0.1.20
PORTREVISION=	5
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sony.co.jp/pub/unsupported/src/ \
		ftp://ftp.cs.titech.ac.jp/pub/japanese/sj3/
MASTER_SITES+=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	nork

PATCH_SITES=	http://quasiquote.org/files/
PATCHFILES=	${PORTNAME}-qq-2.0.1.21.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	hiroo+freebsd@oikumene.gcd.org
COMMENT=	A Japanese input method

USE_RC_SUBR=	sj3.sh
USE_IMAKE=	yes

MAN1=		sj3.1 sj3dic.1 sj3mkdic.1 sj3serv.1
MANLANG=	ja
MANCOMPRESSED=	no
PORTDOCS=	Nihongo.ps.Z hinsi.ms makedict.ms sj3lib.ms sj3serv.ms

# NOTE : You must not use 'xmkmf -a', because the running 'make depend' caused a error.

.include <bsd.port.pre.mk>

pre-configure:
	${REINPLACE_CMD} -e "\#^SJ3TOP#s#=.*#= ${PREFIX}#" \
		-e "\#^SJ3DICTDIR#s#=.*#= \\$$\(SJ3LIBDIR)/sj3/dict#" \
		-e "\#^SJ3VARRUNDIR#s#=.*#= ${DESTDIR}\\$$\(VARDIR)/run/sj3#" \
		${WRKSRC}/sj3.tmpl

do-configure:
	( cd $(WRKSRC) ; ${XMKMF} ; make Makefiles )

pre-install:
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

.include <bsd.port.post.mk>
