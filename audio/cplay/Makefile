# New ports collection makefile for:	cplay
# Date created: 	1 November 2001
# Whom: 		Jochem Kossen
#
# $FreeBSD$
#

PORTNAME=	cplay
PORTVERSION=	1.45
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.tf.hut.fi/~flu/cplay/ \
		http://www.tf.hut.fi/~flu/cplay/old/

MAINTAINER=	j.kossen@home.nl

BUILD_DEPENDS=	gettext:${PORTSDIR}/devel/gettext

USE_GMAKE=	yes
USE_PYTHON=	yes
MAN1=		cplay.1

MAKE_ARGS+=	PREFIX="${PREFIX}"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/cplay
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/cplay
	${INSTALL_MAN} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/cplay
	${INSTALL_MAN} ${WRKSRC}/TODO ${PREFIX}/share/doc/cplay
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
