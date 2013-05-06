# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	latrine
PORTVERSION=	1.0.0
CATEGORIES=	games
MASTER_SITES=	http://alioth.debian.org/frs/download.php/3085/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses-based LAnguage TRaINEr

LICENSE=	GPLv3

BUILD_DEPENDS=	p5-DBI>0:${PORTSDIR}/databases/p5-DBI

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_CSTD=	gnu89
USE_SQLITE=	3
USE_PERL5_BUILD=yes
USES=		gettext ncurses
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -D_XOPEN_SOURCE_EXTENDED
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		latrine.1

post-patch:
	@${FIND} ${WRKSRC} -name "*.c" | ${XARGS} ${REINPLACE_CMD} -e \
		's|<ncursesw/|<|'

.include <bsd.port.mk>
