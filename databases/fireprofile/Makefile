# New ports collection makefile for:	fireprofile
# Date created:		Mon 13 May 15:00:00 WST 2002
# Whom:			Dean Hollister <dean@odyssey.apana.org.au>
#
# $FreeBSD$
#

PORTNAME=	fireprofile
PORTVERSION=    0.1.2
CATEGORIES=     databases
MASTER_SITES=   http://firestuff.org/projects/ \
		http://www.wa.apana.org.au/~dean/sources/ \
		ftp://ftp.wa.apana.org.au/pub/pc/unix/packages/
DISTNAME=	fireprofile
EXTRACT_SUFX=   -0.1.2.tar.gz

MAINTAINER=     dean@odyssey.apana.org.au
COMMENT=	Library to help profiling where programs are using MySQL

MAN3=		libfireprofile.3
PLIST_FILES=	lib/libfireprofile.so

# This port does not work with 4.x
USE_MYSQL=	yes
DEFAULT_MYSQL_VER=	323
WANT_MYSQL_VER=	323

.if ${MACHINE_ARCH:L} == amd64
CFLAGS+=	-fPIC
.endif
.include <bsd.port.mk>
