# New ports collection makefile for:	toppler
# Date created:				18 Jan 2002
# Whom:					Dom Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	toppler
PORTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A game where you have to climb the tower and avoid the monsters

USE_GNOME=	gnometarget
USE_SDL=	mixer sdl
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"  \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--localstatedir=/var/games

MAN6=		toppler.6

post-patch:
	@${REINPLACE_CMD} -e \
		's|DATA install-dist_pkgdocDATA|DATA|g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${CHOWN} root:games ${PREFIX}/bin/toppler
	@${CHMOD} g+s ${PREFIX}/bin/toppler
	@${SETENV} "PKG_PREFIX=${PREFIX}" \
		${SH} pkg-install ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
