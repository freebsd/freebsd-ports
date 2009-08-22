# New ports collection makefile for:	varconf
# Date created:				29 March 2001
# Whom:					Oliver Lehmann <lehmann@ans-netz.de>
#
# $FreeBSD$
#

PORTNAME=	varconf
PORTVERSION=	0.6.6
CATEGORIES=	devel
MASTER_SITES=	SF/worldforge/${PORTNAME}%20%28config%20lib%29/${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A Configuration System for the STAGE Server

LIB_DEPENDS=	sigc-2.0:${PORTSDIR}/devel/libsigc++20

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|: install-docDATA|:|g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in README COPYING AUTHORS THANKS NEWS
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
.include <bsd.port.mk>
