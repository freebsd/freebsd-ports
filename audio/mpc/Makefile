# New ports collection makefile for:	mpc
# Date created:		Oct 02 2003
# Whom:			Mark Reidel <ports@mark.reidle.info>
#
# $FreeBSD$
#

PORTNAME=	mpc
PORTVERSION=	0.11.2
CATEGORIES=	audio ipv6
MASTER_SITES=	http://mercury.chem.pitt.edu/~shank/

MAINTAINER=	ports@mark.reidel.info
COMMENT=	Command line client for the musicpd

GNU_CONFIGURE=	yes
OPTIONS=	ICONV "Support for international characters" on \

CFLAGS+=	-I${PREFIX}/include

MAN1=		mpc.1

.include <bsd.port.pre.mk>

CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \

.ifdef(WITHOUT_ICONV)
CONFIGURE_ARGS+=--disable-iconv
.else
USE_ICONV=	yes
.endif
PLIST_FILES=bin/mpc
PLIST_DIRS=%%EXAMPLESDIR%%
PLIST_FILES+=%%EXAMPLESDIR%%/mpc-bashrc
.ifndef(NOPORTDOCS)
PLIST_DIRS+=%%DOCSDIR%%
PLIST_FILES+=%%DOCSDIR%%/AUTHORS
PLIST_FILES+=%%DOCSDIR%%/README
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mpc ${PREFIX}/bin/
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/mpc-bashrc ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/mpc.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.post.mk>
