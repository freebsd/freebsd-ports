# New ports collection makefile for:	gawk+mb
# Date created:		5 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

PORTNAME=	gawk
PORTVERSION=	3.0.4
PORTREVISION=	1
CATEGORIES=	japanese lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g

PATCH_SITES=	http://www.hinadori.dyn.to/~wills/program/
PATCHFILES=	${PORTNAME}mb114.diff.gz
PATCH_DIST_STRIP=	-p1

MAN1=		gawk.1 igawk.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/OREADME.MB ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README.MB ${PREFIX}/share/doc/${PKGBASE}
.endif

.include <bsd.port.mk>
