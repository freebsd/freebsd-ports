# New ports collection makefile for: fly
# Date created:         30 December 1997
# Whom:                 Juergen Unger <j.unger@choin.net>
#
# $FreeBSD$
#

PORTNAME=	fly
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://martin.gleeson.com/%SUBDIR%/ \
		http://members.optushome.com.au/martingleeson/%SUBDIR%/ \
		http://www.w3perl.com/%SUBDIR%/
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
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
