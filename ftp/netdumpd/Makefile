PORTNAME=	netdumpd
PORTVERSION=	20220406
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	LOCAL/markj

MAINTAINER=	markj@FreeBSD.org
COMMENT=	UDP server capable of handling netdump transfers
WWW=		https://github.com/markjdb/netdumpd

LICENSE=	BSD2CLAUSE

MAKE_ARGS+=	BINDIR=${PREFIX}/sbin
MAKE_ARGS+=	MANDIR=${PREFIX}/share/man/man
MAKE_ARGS+=	SCRIPTSDIR=${PREFIX}/etc/rc.d

PLIST_FILES=	sbin/${PORTNAME} share/man/man8/${PORTNAME}.8.gz etc/rc.d/${PORTNAME}

USES+=		uidfix

.include <bsd.port.mk>
