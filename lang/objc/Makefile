# New ports collection makefile for:    objc compiler
# Version required:     1.12
# Date created:         14 March 1997
# Whom:                 chuckr@freebsd.org
#
# $Id: Makefile,v 1.1.1.1 1997/03/18 22:53:47 chuckr Exp $
#

DISTNAME=       objc
PKGNAME=        objc-1.1.12
CATEGORIES=     lang
MASTER_SITES=   http://www.can.nl/~stes/Software/

MAINTAINER=     chuckr@freebsd.org

HAS_CONFIGURE=	yes

SYSNAME!=	uname -r

.if ${SYSNAME} == "3.0-CURRENT"
DISTFILES=	objc1.1.12-i386-unknown-freebsd3.0.tar.gz
WRKSRC=		$(WRKDIR)/objc1.1.12-i386-unknown-freebsd3.0
.elif ${SYSNAME} == "2.2-RELEASE"
DISTFILES=	objc1.1.12-i386-unknown-freebsd2.2.tar.gz
WRKSRC=		$(WRKDIR)/objc1.1.12-i386-unknown-freebsd2.2
.elif (${SYSNAME} == "2.1.7-RELEASE" || ${SYSNAME} == "2.1.6-RELEASE" || ${SYSNAME} == "2.1.5-RELEASE")
DISTFILES=	objc1.1.12-i386-unknown-freebsd2.1.7.tar.gz
WRKSRC=		$(WRKDIR)/objc1.1.12-i386-unknown-freebsd2.1.7
.else
BROKEN=		Only suppports FreeBSD current, 2.2, and 2.1.{7,6,5}.  Sorry!
.endif

MAKE_ENV=	env OBJCDIR=${WRKSRC} CFLAGS=-O
CONFIGURE_ENV=	OBJCC="env OBJCDIR=$(WRKSRC) $(WRKSRC)/bin/objc -q -g -noI -noLibs" CFLAGS=-O

.include <bsd.port.mk>
