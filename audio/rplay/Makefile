# New ports collection makefile for:	rplay - Network audio player
# Date created:		16 March 1995
# Whom:			rmallory@csusb.edu
#
# $FreeBSD$
#

PORTNAME=	rplay
PORTVERSION=	3.3.2
CATEGORIES=	audio
MASTER_SITES=	http://rplay.doit.org/dist/

MAINTAINER=	rmallory@csusb.edu

LIB_DEPENDS=	gsm.1:${PORTSDIR}/audio/gsm

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		rplay.1 rptp.1
MAN5=		rplay.conf.5 rplay.helpers.5 rplay.hosts.5 rplay.servers.5
MAN8=		rplayd.8

INFO_FILES=	RPLAY.info RPTP.info librplay.info rplayd.info

post-extract:
	@${CP} ${WRKSRC}/doc/rplay.texi ${WRKSRC}/doc/rplayd.texi

post-install:
.for info in ${INFO_FILES}
	@install-info ${PREFIX}/info/${info} ${PREFIX}/info/dir
.endfor
.if !exists(${PREFIX}/etc/rc.d/rplayd.sh)
	@${ECHO} "===>   Installing ${PREFIX}/etc/rc.d/rplayd.sh startup file"
	@${INSTALL_SCRIPT} -m 751 ${FILESDIR}/rplayd.sh ${PREFIX}/etc/rc.d/rplayd.sh
.endif
.if !exists(${PREFIX}/etc/rplay.hosts)
	@${ECHO} localhost > ${PREFIX}/etc/rplay.hosts
.endif

.include <bsd.port.mk>
