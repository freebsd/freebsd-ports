# New ports collection makefile for:	icegenerator
# Date created:				18 August 2004
# Whom:				Nadelyaev Stanislav <funkblaster@n11.bmstu.ru>
#
# $FreeBSD$
#

PORTNAME=		icegenerator
PORTVERSION=		0.5.4
PORTREVISION=		1
CATEGORIES=		audio net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		funkblaster@n11.bmstu.ru
COMMENT=		Direct streaming generator for Icecast/Shoutcast

LIB_DEPENDS=		shout.4:${PORTSDIR}/audio/libshout2

INSTALLS_SHLIB=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/etc/icegenerator.conf.dist ${PREFIX}/etc
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
