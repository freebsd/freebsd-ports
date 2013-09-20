# Created by: wcarey
# $FreeBSD$

PORTNAME=	ledger
PORTVERSION=	2.6.3
PORTREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	http://cloud.github.com/downloads/jwiegley/${PORTNAME}/

MAINTAINER=	woodycarey@hotmail.com
COMMENT=	John Wiegley's command line accounting program

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp \
		pcre:${PORTSDIR}/devel/pcre \
		xmltok:${PORTSDIR}/www/libwww \
		xmlparse:${PORTSDIR}/www/libwww

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/w3c-libwww
LDFLAGS+=	-L${LOCALBASE}/lib

NO_INSTALL_MANPAGES=	yes
INFO=	ledger

NO_STAGE=	yes
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
