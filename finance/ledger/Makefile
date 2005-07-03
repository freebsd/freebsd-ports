# New ports collection makefile for:   ledger
# Date created:        June 25th, 2005
# Whom:                wcarey
#
# $FreeBSD$
#

PORTNAME=	ledger
PORTVERSION=	2.3
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED} \
		http://www.badplandude.com/~wcarey/ledger/
MASTER_SITE_SUBDIR=ledger

MAINTAINER=     woodycarey@hotmail.com
COMMENT=	John Wiegley's command line accounting program

LIB_DEPENDS=	gmp:${PORTSDIR}/math/libgmp4 \
		pcre:${PORTSDIR}/devel/pcre \
		xmltok:${PORTSDIR}/www/libwww \
		xmlparse:${PORTSDIR}/www/libwww

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	CPPFLAGS="-I${PREFIX}/include" LDFLAGS="-L${PREFIX}/lib"

NO_INSTALL_MANPAGES=	yes
INFO=	ledger

# we need to write our own do-install, as the configure script produces
# a Makefile which respects $prefix, not ${PREFIX} during the install
do-install:
	${INSTALL_DATA} ${WRKSRC}/ledger.info ${PREFIX}/info/
	${INSTALL_PROGRAM} ${WRKSRC}/ledger	${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/libledger.a ${PREFIX}/lib/
	${MKDIR} ${PREFIX}/include/ledger
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/ledger/
	${MKDIR} ${EXAMPLESDIR}
	${MKDIR} ${EXAMPLESDIR}/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${EXAMPLESDIR}/scripts/
	${INSTALL_DATA} ${WRKSRC}/sample.dat ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/setup.py ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ledger.el ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ledger.vim ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ledger.texi ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/main.py ${EXAMPLESDIR}

post-install:
	${CAT} pkg-message

.include <bsd.port.mk>
