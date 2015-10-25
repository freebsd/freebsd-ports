# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	totd
PORTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	dns ipv6
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/Vermicelli/

MAINTAINER=	ed@FreeBSD.org
COMMENT=	DNS proxy that supports IPv6 <==> IPv4 record translation

USES=		desthack uidfix

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
USE_RC_SUBR=	totd
GNU_CONFIGURE=	yes

PLIST_FILES=	etc/totd.conf.sample sbin/totd \
		man/man8/totd.8.gz

EXTRA_PATCHES=	${FILESDIR}/extra-patch-ne_mesg.c \
		${FILESDIR}/extra-patch-tcp_response.c

MAKE_ARGS=	CC="${CC}"

post-patch:
	${REINPLACE_CMD} -e 's/-o bin -g bin//g; s/-o root -g wheel//g' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${FILESDIR}/totd.conf.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
