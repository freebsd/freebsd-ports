# New ports collection makefile for:	gtkballs
# Date created:				11 November 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	gtkballs
PORTVERSION=	3.0.1
CATEGORIES=	games
MASTER_SITES=	http://gtkballs.antex.ru/dist/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Lines-like simple logic game for X Window System

LIB_DEPENDS=	gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--localstatedir=${DATADIR}

MAN6=		gtkballs.6x

post-patch:
	@${REINPLACE_CMD} -e 's|^install-data-local|#install-data-local|g' \
		${WRKSRC}/Makefile.in

post-install:
	${CHMOD} 2755 ${PREFIX}/bin/gtkballs
	${CHOWN} root:games ${PREFIX}/bin/gtkballs
	${CHMOD} 0666 ${DATADIR}/gtkballs-scores
	${CHOWN} root:games ${DATADIR}/gtkballs-scores
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in README README.russian TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
