# New ports collection makefile for:	ncmpc
# Date created:		Apr 14 2004
# Whom:			Mark Reidel <ports@mark.reidel.info>
#
# $FreeBSD$
#

PORTNAME=	ncmpc
PORTVERSION=	0.10.0
CATEGORIES=	audio
MASTER_SITES=	http://hem.bredband.net/kaw/ncmpc/files/ \
		http://mercury.chem.pitt.edu/~shank/

MAINTAINER=	ports@mark.reidel.info
COMMENT=	Ncurses client for the musicpd

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		glib-2.0.400:${PORTSDIR}/devel/glib20

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_ICONV=	yes

MAN1=		ncmpc.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ncmpc ${PREFIX}/bin/
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ncmpcrc.sample ${EXAMPLESDIR}/ncmpcrc
	${INSTALL_DATA} ${WRKSRC}/doc/ncmpc.lirc ${EXAMPLESDIR}/
	${INSTALL_MAN} ${WRKSRC}/doc/ncmpc.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
