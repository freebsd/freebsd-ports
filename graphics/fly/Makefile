# New ports collection makefile for: fly
# Date created:         30 December 1997
# Whom:                 Juergen Unger <j.unger@choin.net>
#
# $FreeBSD$
#

PORTNAME=	fly
PORTVERSION=	2.0.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://members.optushome.com.au/martingleeson/%SUBDIR%/ \
		http://martin.gleeson.com/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}/dist

MAINTAINER=	corky1951@comcast.net
COMMENT=	Simple drawing language to generate GIFs on the fly

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -I${LOCALBASE}/include fly.c -o fly \
		-L${LOCALBASE}/lib -lgd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fly ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
