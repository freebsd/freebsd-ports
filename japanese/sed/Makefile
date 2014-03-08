# Created by: Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
# $FreeBSD$

PORTNAME=	sed
PORTVERSION=	3.02
PORTREVISION=	2
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU sed + multi-byte extension

DEPRECATED=	Unmaintained since 1999
EXPIRATION_DATE=	2014-04-10
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

INFO=		sed

PATCH_SITES=	http://www.hinadori.atnifty.com/~wills/program/
PATCHFILES=	${PORTNAME}mb109.diff.gz
PATCH_DIST_STRIP=	-p1

MAN1=		sed.1

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/OREADME.MB ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README.MB ${PREFIX}/share/doc/${PKGBASE}
.endif

.include <bsd.port.mk>
