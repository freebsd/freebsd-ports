# New ports collection makefile for:	rpm
# Version required:	2.3.9
# Date created:		23 January 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.3 1997/04/03 07:07:01 tg Exp $
#

DISTNAME=	rpm-2.3.9
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.redhat.com/pub/redhat/code/rpm/

MAINTAINER=	tg@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAN8=		rpm.8 rpm2cpio.8

pre-install:
	${MKDIR} ${PREFIX}/include/rpm

.include <bsd.port.mk>
