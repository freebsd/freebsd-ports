# New ports collection makefile for:	Ming
# Date created:		14 October 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ming
PORTVERSION=	0.0.2e
CATEGORIES=	graphics
MASTER_SITES=	http://www.opaque.net/ming/
EXTRACT_SUFX=	.tgz

MAINTAINER=	knu@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME}/src

DOCS=		CHANGES \
		CREDITS \
		Makefile \
		README \
		TODO

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/

pre-install:
	${MKDIR} ${PREFIX}/include/ming

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ming
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/../${f} ${PREFIX}/share/doc/ming/
.endfor
	${CP} -R ${WRKSRC}/../docs/* ${PREFIX}/share/doc/ming/
	${LN} -sf ../doc/ming/examples ${PREFIX}/share/examples/ming
.endif

.include <bsd.port.mk>
