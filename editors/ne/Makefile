# New ports collection makefile for:	ne
# Date created:		2005-07-21
# Whom:			Andrej Zverev <az@inec.ru>
#
# $FreeBSD$
#

PORTNAME=	ne
PORTVERSION=	1.40
CATEGORIES=	editors
MASTER_SITES=	http://ne.dsi.unimi.it/

MAINTAINER=	az@inec.ru
COMMENT=	Nice and powerfull editor

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400010
LIB_DEPENDS+=	ncurses:${PORTSDIR}/devel/ncurses
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_GMAKE=	yes
USE_PERL5=	yes
MAKEFILE=	makefile
ALL_TARGET=	ne
MAKE_ARGS=	CFLAGS="${CFLAGS} -DNOWCHAR" CC="${CC}" \
		GLOBALDIR="${DATADIR}"

MAN1=	ne.1

post-patch:
	@${PERL5} -pi -e 's|tmpnam\(|mkstemp\(|g' ${WRKSRC}/actions.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ne ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA}	${WRKSRC}/../doc/default.keys ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/../doc/default.menus ${DATADIR}/
	${INSTALL_MAN}	${WRKSRC}/../doc/ne.1	${PREFIX}/man/man1

.include <bsd.port.post.mk>
