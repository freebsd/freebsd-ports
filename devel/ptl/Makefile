# New ports collection makefile for:	PTL
# Date created:		8 April 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ptl
PORTVERSION=	2.1.8
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.media.osaka-cu.ac.jp/pub/%SUBDIR%/ \
		ftp://ftp.ics.es.osaka-u.ac.jp/pub/mirrors/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME:U}/${PORTNAME:U}2
DISTNAME=	${PORTNAME:U}-${PORTVERSION}

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf

MAKE_ARGS=	prefix="${PREFIX}"
INSTALLS_SHLIB=	yes

DOCS=		COPYING		ChangeLog	FAQ		NEWS \
		PROBLEMS	README		README.PDB	README.jp \
		WISHLIST	doc/manual.ps.gz

post-patch:
	${PERL} -i -pe 's/-O[2-6]/${CFLAGS}/g' \
		${WRKSRC}/Util/Makefile.in \
		${WRKSRC}/Util/configure \
		${WRKSRC}/libaltsys/utils/configure

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/${PORTNAME:U}
	cd ${PREFIX} && ( \
		find ${PORTNAME:U} -type f -o -type l | sort; \
		find ${PORTNAME:U} -type d | sort -r | ${SED} 's/^/@dirrm /'; \
	) >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/doc/PTL.info* ${PREFIX}/info/
.for f in ${DOCS}
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
