# New ports collection makefile for:	cuetools
# Date created:		30 December 2003
# Whom:			Vincent Tantardini <vinc@FreeBSD-fr.org>
#
# $FreeBSD$
#

PORTNAME=	cuetools
PORTVERSION=	0.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of utilities for working with cue files and toc files

USE_REINPLACE=	yes

pre-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
.for F in README README.formats ChangeLog
	${INSTALL_MAN} ${WRKSRC}/${F} ${DOCSDIR}
.endfor
.for E in EXAMPLE.cuerenamerc EXAMPLE.useage
	${INSTALL_MAN} ${WRKSRC}/${E} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
