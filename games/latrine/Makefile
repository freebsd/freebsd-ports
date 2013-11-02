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
USE_PERL5=	build
USES=		gettext gmake ncurses perl5
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -D_XOPEN_SOURCE_EXTENDED
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${FIND} ${WRKSRC} -name "*.c" | ${XARGS} ${REINPLACE_CMD} -e \
		's|<ncursesw/|<|'

.include <bsd.port.mk>
