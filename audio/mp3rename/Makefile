# New ports collection makefile for: mp3rename
# Version required:     0.4
# Date created:         6 Januari 2000
# Whom:                 Sander Janssen <janssen@rendo.dekooi.nl>
#
# $FreeBSD$
#

DISTNAME=      mp3rename-0.4
CATEGORIES=    audio
MASTER_SITES=  http://www.rendo.dekooi.nl/~janssen/

MAINTAINER=    janssen@rendo.dekooi.nl

FETCH_BEFORE_ARGS=     -b

MAN1=          mp3rename.1
MANCOMPRESSED=         yes

post-install:
	strip ${PREFIX}/bin/mp3rename

.include <bsd.port.mk>
