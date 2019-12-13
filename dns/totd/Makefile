# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	totd
PORTVERSION=	1.5.1
PORTREVISION=	2
CATEGORIES=	dns
MASTER_SITES=	https://BSDforge.com/projects/source/dns/totd/

MAINTAINER=	ed@FreeBSD.org
COMMENT=	DNS proxy that supports IPv6 <==> IPv4 record translation

USES=		desthack uidfix

USE_RC_SUBR=	totd
GNU_CONFIGURE=	yes

PLIST_FILES=	"@sample etc/totd.conf.sample" \
		man/man8/totd.8.gz \
		sbin/totd

EXTRA_PATCHES=	${FILESDIR}/extra-patch-ne_mesg.c \
		${FILESDIR}/extra-patch-tcp_response.c

MAKE_ARGS=	CC="${CC}"

post-patch:
	${REINPLACE_CMD} -e 's/-o bin -g bin//g; s/-o root -g wheel//g' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${FILESDIR}/totd.conf.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
