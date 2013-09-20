# Created by: Roy Marples <roy@marples.name>
# $FreeBSD$

PORTNAME=	openresolv
PORTVERSION=	1.1
CATEGORIES=	dns
MASTER_SITES= http://roy.marples.name/downloads/openresolv/ \
  ftp://roy.marples.name/pub/openresolv/

MAINTAINER=	roy@marples.name
COMMENT=	A resolvconf compatible framework for managing resolv.conf

USE_BZIP2=	yes

MAN8=	resolvconf.8

SUB_FILES=	pkg-deinstall pkg-message
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGMESSAGE=	${WRKDIR}/pkg-message

NO_STAGE=	yes
post-install:
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.mk>
