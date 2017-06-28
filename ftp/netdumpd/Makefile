# Created by: Mark Johnston <markj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	netdumpd
PORTVERSION=	20170615
CATEGORIES=	ftp
MASTER_SITES=	LOCAL/markj

MAINTAINER=	markj@FreeBSD.org
COMMENT=	UDP server capable of handling netdump transfers

LICENSE=	BSD2CLAUSE

IGNORE_FreeBSD_10=	Depends on libcasper

MAKE_ARGS+=	BINDIR=${PREFIX}/sbin
MAKE_ARGS+=	MANDIR=${PREFIX}/man/man
MAKE_ARGS+=	SCRIPTSDIR=${PREFIX}/etc/rc.d

PLIST_FILES=	sbin/${PORTNAME} man/man8/${PORTNAME}.8.gz etc/rc.d/${PORTNAME}

.include <bsd.port.mk>
