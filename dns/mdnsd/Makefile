# New ports collection makefile for:    mdnsd
# Date created:		2003/05/24
# Whom:			Dan Pelleg <daniel+mdnsd@pelleg.org>
#
# $FreeBSD$
#

PORTNAME=	mdnsd
PORTVERSION=	0.7G
CATEGORIES=	dns
MASTER_SITES=	http://dotlocal.org/${PORTNAME}/ \
		http://web.cs.cmu.edu/~dpelleg/download/

MAINTAINER=	daniel+mdnsd@pelleg.org
COMMENT=	Advertise a service via Rendezvous

do-install:
	@${ECHO_MSG} "Installing files"
.for i in mhttp mquery
	@${INSTALL} ${COPY} ${_BINOWNGRP} ${WRKSRC}/${i} ${PREFIX}/bin
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
