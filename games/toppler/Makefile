# New ports collection makefile for:	toppler
# Date created:				18 Jan 2002
# Whom:					Dom Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	toppler
PORTVERSION=	1.1.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	toppler

MAINTAINER=	dom@happygiraffe.net
COMMENT=	A game where you have to climb the tower and avoid the monsters

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_SDL=	mixer sdl
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"  \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="-lintl"
CONFIGURE_ARGS=	--program-transform-name= --localstatedir=/var/games

MAN6=		toppler.6

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	can not be compiled because it requires mbrtowc() in libc
.endif

post-install:
	@${CHOWN} root:games ${PREFIX}/bin/toppler
	@${CHMOD} g+s ${PREFIX}/bin/toppler
	@${SETENV} "PKG_PREFIX=${PREFIX}" \
		${SH} pkg-install ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
