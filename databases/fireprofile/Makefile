# New ports collection makefile for:	fireprofile
# Date created:		Mon 13 May 15:00:00 WST 2002
# Whom:			Dean Hollister <dean@odyssey.apana.org.au>
#
# $FreeBSD$
#

PORTNAME=	fireprofile
PORTVERSION=    0.1.2
CATEGORIES=     databases
MASTER_SITES=   http://ares.penguinhosting.net/~ian/projects/ \
		http://www.wa.apana.org.au/~dean/sources/ \
		ftp://ftp.wa.apana.org.au/pub/pc/unix/packages/
DISTNAME=	fireprofile
EXTRACT_SUFX=   -0.1.2.tar.gz

MAINTAINER=     dean@odyssey.apana.org.au
COMMENT=	Library to help profiling where programs are using MySQL

BUILD_DEPENDS=	${LOCALBASE}/include/mysql/mysql.h:${PORTSDIR}/databases/mysql323-server

MAN3=		libfireprofile.3
PLIST_FILES=	lib/libfireprofile.so

.include <bsd.port.mk>
