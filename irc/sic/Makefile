PORTNAME=	sic
PORTVERSION=	0.23a
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.funet.fi/pub/unix/irc/sic/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Another 'Internet Relay Chat' Client

LICENSE=	GPLv2

USES=		ncurses tar:tgz
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
PLIST_SUB=	VERSION="${PORTVERSION}"

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-${PORTVERSION}

.include <bsd.port.post.mk>
