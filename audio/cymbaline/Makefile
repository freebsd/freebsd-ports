# ex:ts=8
# New ports collection makefile for:	cymbaline
# Date created:			Jun 20, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cymbaline
PORTVERSION=	0.9r
PORTREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	http://www.silmarill.org/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	mpg123 console frontend

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123 \
		aumix:${PORTSDIR}/audio/aumix

USE_PYTHON=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cymbaline.py ${PREFIX}/bin/cymbaline
.for file in ID3.py cycolors.py mp3.py
	${INSTALL_DATA} ${WRKSRC}/${file} ${PYTHON_SITELIBDIR}
.endfor

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
