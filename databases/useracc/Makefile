# Created by: Konrad Heuer
# $FreeBSD$

PORTNAME=	useracc
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	ftp://gwdu111.gwdg.de/pub/FreeBSD/misc/ \
		ftp://gwdu112.gwdg.de/pub/FreeBSD/misc/

MAINTAINER=	kheuer@gwdg.de
COMMENT=	Special purpose database application

BROKEN=		unfetchable

PLIST_FILES=	bin/useracc etc/rc.d/useracc.sh.sample man/man1/useracc.1.gz

CFLAGS+=	-DFreeBSD

.include <bsd.port.mk>
