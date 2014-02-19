# Created by: Dan Pelleg <daniel+mdnsd@pelleg.org>
# $FreeBSD$

PORTNAME=	mdnsd
PORTVERSION=	0.7G
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://www.cs.cmu.edu/~dpelleg/download/

MAINTAINER=	daniel+mdnsd@pelleg.org
COMMENT=	Advertise a service via Rendezvous

PLIST_FILES=	bin/mhttp bin/mquery

do-install:
.for f in mhttp mquery
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
