# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	gtkballs
PORTVERSION=	3.1.5
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	http://gtkballs.antex.ru/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lines-like simple logic game for X Window System

USES=		gettext gmake pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--localstatedir=${DATADIR}

MAN6=		gtkballs.6x

NO_STAGE=	yes
post-install:
	${CHMOD} 2755 ${PREFIX}/bin/gtkballs
	${CHOWN} root:games ${PREFIX}/bin/gtkballs
	${CHMOD} 0664 ${DATADIR}/gtkballs-scores
	${CHOWN} root:games ${DATADIR}/gtkballs-scores
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in README README.russian TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
