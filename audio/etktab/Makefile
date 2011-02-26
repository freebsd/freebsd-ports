# New ports collection makefile for:	etktab
# Date created:		29 January 2003
# Whom:			Juha Erkkilä <erkkila@cc.jyu.fi>
#
# $FreeBSD$
#

PORTNAME=	etktab
PORTVERSION=	3.2
PORTREVISION=	1
CATEGORIES=	audio tcl tk
MASTER_SITES=	SF/${PORTNAME}/eTktab/${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} canada_multi-3.2.etk \
			dvorak-3.2.etk uk-3.2.etk us-3.2.etk
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Guitar tablature editor

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/eTktab-${PORTVERSION}

post-extract:
.for FILE in canada_multi-3.2.etk dvorak-3.2.etk uk-3.2.etk us-3.2.etk
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${FILE} ${WRKSRC}
.endfor

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/eTktab ${PREFIX}/bin/etktab
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in CHANGES.html LICENSE.html README.html eTktab-small.xpm eTktab.xpm \
		canada_multi-3.2.etk dvorak-3.2.etk uk-3.2.etk us-3.2.etk
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
