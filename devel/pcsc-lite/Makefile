# New ports collection makefile for:   pcsc-lite
# Date created:                15 Oct 2001
# Whom:                        Toni Andjelkovic <toni@soth.at>
#
# $FreeBSD$
#

PORTNAME=	pcsc-lite
PORTVERSION=	1.1.2.b.5
CATEGORIES=	devel security
MASTER_SITES=	http://alioth.debian.org/download.php/160/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b./beta/}

MAINTAINER=	toni@soth.at
COMMENT=	A smartcard development library

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.b.5//}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

INSTALLS_SHLIB=	yes
CONFIGURE_ENV+=	PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS+=--enable-debug \
		--enable-syslog \
		--enable-runpid=/var/run/pcscd.pid \
		--enable-ipcdir=/var/tmp/ \
		--enable-confdir=${PREFIX}/etc/ \
		--enable-usbdropdir=${PREFIX}/pcsc/drivers/ \
		--enable-muscledropdir=${PREFIX}/pcsc/services/ \
		--enable-threadsafe
PKGMESSAGE=	${WRKDIR}/pkg-message
MAN1=		formaticc.1
MAN8=		bundleTool.8 pcscd.8

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README.DAEMON ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/pcsc-lite-0.8.7.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/muscle-api-1.3.0.pdf ${DOCSDIR}
.endif
	@${MKDIR} ${PREFIX}/pcsc/drivers
	@${MKDIR} ${PREFIX}/pcsc/services
	${INSTALL_DATA} ${WRKSRC}/etc/reader.conf \
		${PREFIX}/etc/reader.conf.sample
	${INSTALL_SCRIPT} ${FILESDIR}/pcscd.sh \
		${PREFIX}/etc/rc.d/pcscd.sh.sample
	@${SED} 's,%%PREFIX%%,${PREFIX},g' < ${FILESDIR}/pkg-message.in > \
		${WRKDIR}/pkg-message
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
