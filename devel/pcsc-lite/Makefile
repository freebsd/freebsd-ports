# New ports collection makefile for:   pcsc-lite
# Date created:                15 Oct 2001
# Whom:                        Toni Andjelkovic <toni@ants.at>
#
# $FreeBSD$
#

PORTNAME=	pcsc-lite
PORTVERSION=	1.1.1
CATEGORIES=	devel security
MASTER_SITES=	http://www.linuxnet.com/middleware/files/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	toni@soth.at

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES+=	build/aclocal.m4

INSTALLS_SHLIB=	yes
CONFIGURE_ARGS+=	--enable-debug \
			--enable-syslog \
			--enable-runpid=/var/run/pcscd.pid \
			--enable-confdir=${PREFIX}/etc \
			--disable-threadsafe
PKGMESSAGE=	${WRKDIR}/pkg-message
MAN8=		pcscd.8

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README.DAEMON ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/pcsc-lite-0.8.7.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/muscle-api-1.3.0.pdf ${DOCSDIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/etc/reader.conf \
		${PREFIX}/etc/reader.conf.sample
	${INSTALL_SCRIPT} ${FILESDIR}/pcscd.sh \
		${PREFIX}/etc/rc.d/pcscd.sh.sample
	@${SED} 's,%%PREFIX%%,${PREFIX},g' < ${FILESDIR}/pkg-message.in > \
		${WRKDIR}/pkg-message
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
