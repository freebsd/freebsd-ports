# New ports collection makefile for:   pcsc-lite
# Date created:                15 Oct 2001
# Whom:                        Toni Andjelkovic <toni@ants.at>
#
# $FreeBSD$
#

PORTNAME=	pcsc-lite
PORTVERSION=	1.0.1
CATEGORIES=	devel security
MASTER_SITES=	http://www.linuxnet.com/middleware/files/

MAINTAINER=	toni@ants.at

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

INSTALLS_SHLIB=	yes
CONFIGURE_ARGS+=	--enable-syslog --enable-daemon
PKGMESSAGE=	${WRKDIR}/pkg-message

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/reader.conf \
		${PREFIX}/etc/reader.conf.sample
	${INSTALL_SCRIPT} ${FILESDIR}/pcscd.sh \
		${PREFIX}/etc/rc.d/pcscd.sh.sample
	@${SED} 's,%%PREFIX%%,${PREFIX},g' < ${FILESDIR}/pkg-message.in > \
		${WRKDIR}/pkg-message
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
