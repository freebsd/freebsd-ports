# Ports collection makefile for:  wormux
# Date created:			  Thu Dec 16 18:46:55 EET 2004
# Whom:				  Anton Yudin <toha@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wormux
PORTVERSION=	0.5.0
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/wormux/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	toha@toha.org.ua
COMMENT=	Wormux game

USE_BZIP2=	yes
USE_SDL=	sdl
USE_GETTEXT=	yes
USE_GNOME=	gnomelibs

LIB_DEPENDS+=	clanGUI-0.7:${PORTSDIR}/devel/clanlib-devel
LIB_DEPENDS+=	xml\\+\\+-1.0.1:${PORTSDIR}/textproc/libxml++

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/wormux

CONFIGURE_ARGS+=--prefix=${PREFIX}
GNU_CONFIGURE=yes

.include <bsd.port.pre.mk>

post-install:
.for dir in ${PREFIX}/share/${PORTNAME}
	@${FIND} ${dir} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${dir} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endfor

.include <bsd.port.post.mk>
