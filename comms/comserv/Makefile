# Created by: Brian Dean <bsd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	comserv
PORTVERSION=	1.4.3
CATEGORIES=	comms net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	bsd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provide network access to local serial ports and make remote ports appear local

PLIST_FILES=	sbin/comservd etc/comservd.conf.sample \
		etc/rc.d/comservd.sh.sample man/man8/comservd.8.gz

post-patch:
	@${REINPLACE_CMD} -E \
		-e '/(INSTALL_|gzip)/ s,(BIN|CONF|MAN|RC)DIR,DESTDIR}$${&,g' \
		-e 's,-o root -g wheel,,' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
