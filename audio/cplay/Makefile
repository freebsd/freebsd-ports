# New ports collection makefile for:	cplay
# Date created: 	1 November 2001
# Whom: 		Jochem Kossen
#
# $FreeBSD$
#

PORTNAME=	cplay
PORTVERSION=	1.49
CATEGORIES=	audio
MASTER_SITES=	http://www.tf.hut.fi/~flu/cplay/ \
		http://www.tf.hut.fi/~flu/cplay/old/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A curses based front-end for various audio players

BUILD_DEPENDS=	gettext:${PORTSDIR}/devel/gettext-old

USE_GMAKE=	yes
USE_PYTHON=	yes
MAN1=		cplay.1

MAKE_ARGS+=	PREFIX="${PREFIX}"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
