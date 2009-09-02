# New ports collection makefile for:   ledger
# Date created:        June 25th, 2005
# Whom:                wcarey
#
# $FreeBSD$
#

PORTNAME=	ledger
PORTVERSION=	2.6.1
PORTREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	SF

MAINTAINER=	woodycarey@hotmail.com
COMMENT=	John Wiegley's command line accounting program

LIB_DEPENDS=	gmp:${PORTSDIR}/math/libgmp4 \
		pcre:${PORTSDIR}/devel/pcre \
		xmltok:${PORTSDIR}/www/libwww \
		xmlparse:${PORTSDIR}/www/libwww

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/w3c-libwww
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

NO_INSTALL_MANPAGES=	yes
INFO=	ledger

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${MKDIR} ${EXAMPLESDIR}/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${EXAMPLESDIR}/scripts/
	${INSTALL_DATA} ${WRKSRC}/sample.dat ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/setup.py ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ledger.vim ${EXAMPLESDIR}
	${RM} -f ${PREFIX}/share/emacs/site-lisp/*.elc
	${CAT} pkg-message

.include <bsd.port.mk>
