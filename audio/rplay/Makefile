# New ports collection makefile for:	rplay - Network audio player
# Date created:		16 March 1995
# Whom:			rmallory@csusb.edu
#
# $FreeBSD$
#

PORTNAME=	rplay
PORTVERSION=	3.3.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://rplay.doit.org/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network audio player

LIB_DEPENDS=	gsm.1:${PORTSDIR}/audio/gsm

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		rplay.1 rptp.1
MAN5=		rplay.conf.5 rplay.helpers.5 rplay.hosts.5 rplay.servers.5
MAN8=		rplayd.8

INFO=		RPLAY RPTP librplay rplayd

post-extract:
	@${CP} ${WRKSRC}/doc/rplay.texi ${WRKSRC}/doc/rplayd.texi

post-install:
.for info in ${INFO}
	@install-info ${PREFIX}/info/${info}.info ${PREFIX}/info/dir
.endfor
	@${ECHO_MSG} "===>	Installing ${PREFIX}/etc/rc.d/rplayd.sh"
	@${ECHO_MSG} "===>	startup file as ${PREFIX}/etc/rc.d/rplayd.sh.sample"
	@${INSTALL_SCRIPT} -m 751 ${FILESDIR}/rplayd.sh ${PREFIX}/etc/rc.d/rplayd.sh.sample
	for na in rplay.conf rplay.helpers rplay.servers rplay.hosts; do \
		${CP} ${WRKSRC}/etc/$$na ${PREFIX}/etc/$$na.sample; \
		if [ ! -f ${PREFIX}/etc/$$na ]; then \
			${CP} ${WRKSRC}/etc/$$na ${PREFIX}/etc/$$na; \
		fi; \
	done
.if !exists(${PREFIX}/etc/rplay.hosts)
	@${ECHO_CMD} localhost > ${PREFIX}/etc/rplay.hosts
.endif
	@${ECHO_CMD} localhost > ${PREFIX}/etc/rplay.hosts.sample

.include <bsd.port.mk>
