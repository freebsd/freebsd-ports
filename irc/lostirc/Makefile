# New ports collection makefile for:	irc/lostirc
# Date created:				01 Jul 2002
# Whom:					Juan Salaverria <rael@vectorstar.net>
#
# $FreeBSD$
#

PORTNAME=	lostirc
PORTVERSION=	0.4.6
PORTREVISION=	6
CATEGORIES=	irc
MASTER_SITES=	SF \
		http://demian.dyndns.org/src/


MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple and minimal IRC client for X

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

USE_GNOME=	gnomehack gnomeprefix gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-kde

MAN1=		lostirc.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog TODO README INSTALL
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
