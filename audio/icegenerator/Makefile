# New ports collection makefile for:	icegenerator
# Date created:				18 August 2004
# Whom:				Nadelyaev Stanislav <funkblaster@n11.bmstu.ru>
#
# $FreeBSD$
#

PORTNAME=		icegenerator
DISTVERSION=		0.5.5-pre2
CATEGORIES=		audio net
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}/0.5.5-pre2

MAINTAINER=		funkblaster@mail.ru
COMMENT=		Direct streaming generator for Icecast/Shoutcast

LIB_DEPENDS=		shout.5:${PORTSDIR}/audio/libshout2

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
CONFIGURE_ARGS=		--exec-prefix=${PREFIX}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/etc/icegenerator.conf.dist ${PREFIX}/etc
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
