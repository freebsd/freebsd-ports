PORTNAME=	netdumpd
PORTVERSION=	20220406
PORTREVISION=	0
CATEGORIES=	ftp
MASTER_SITES=	LOCAL/markj

MAINTAINER=	markj@FreeBSD.org
COMMENT=	UDP server capable of handling netdump transfers

LICENSE=	BSD2CLAUSE

MAKE_ARGS+=	BINDIR=${PREFIX}/sbin
MAKE_ARGS+=	MANDIR=${PREFIX}/man/man
MAKE_ARGS+=	SCRIPTSDIR=${PREFIX}/etc/rc.d

PLIST_FILES=	sbin/${PORTNAME} man/man8/${PORTNAME}.8.gz etc/rc.d/${PORTNAME}

USES+=		uidfix

.include <bsd.port.mk>
