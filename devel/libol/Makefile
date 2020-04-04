# Created by: Vince Valenti <vince@blue-box.net>
# $FreeBSD$

PORTNAME=	libol
PORTVERSION=	0.3.18
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.balabit.com/downloads/files/libol/0.3/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Library needed by syslog-ng

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2020-05-05

USES=		libtool
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

# depends on scsh which is severily broken
post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/make_class

.include <bsd.port.mk>
