# New ports collection makefile for:	bopm
# Date Created:				2004.08.06
# Whom:					Evgueni V. Gavrilov <aquatique@rusunix.org>
#
# $FreeBSD$
#

PORTNAME=	bopm
PORTVERSION=	3.1.2
CATEGORIES=	irc
MASTER_SITES=	http://static.blitzed.org/www.blitzed.org/bopm/files/ \
		ftp://rusunix.org/pub/FreeBSD/distfiles/

MAINTAINER=	aquatique-ports@rambler.ru
COMMENT=	Open proxy monitor and blocker, designed for use with ircds

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc

INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,^[[:space:]]*$$(mkinstalldirs) $$(localstatedir),,' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's,= bopm.conf.sample,= ,' ${WRKSRC}/Makefile.in

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${INSTALL_SCRIPT} -m 555 ${FILESDIR}/bopm.sh.sample ${PREFIX}/etc/rc.d
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
