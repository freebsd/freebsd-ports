# ports collection makefile for:	Berkeley DB
# Version required:                     v2.*
# Date created:				26 Jan 1998
# Whom:					Josh Tiefenbach <josh@ican.net>
#
# $Id: Makefile,v 1.9 1999/03/11 20:33:49 scrappy Exp $
#

DISTNAME=       db-2.7.3
CATEGORIES=	databases
MASTER_SITES=   ftp://ftp.terra.net/pub/sleepycat/

MAINTAINER=	josh@ican.net

Y2K=		http://www.sleepycat.com/faq.html#A8
WWW_SITE=	http://www.sleepycat.com

WRKSRC=         ${WRKDIR}/${DISTNAME}/build_unix

GNU_CONFIGURE=	YES
CONFIGURE_SCRIPT=	../dist/configure
CONFIGURE_ARGS=		--enable-compat185 \
			--enable-dump185 --enable-cxx

post-install:
	@echo ""
	@echo "Java support for ${PKGNAME} is *not* built by default, and requires that you"
	@echo "have a working copy of the JDK (v1.1) installed."
	@echo ""
	@echo "To build java support, please read:"
	@echo ""
	@echo "${WRKDIR}/${DISTNAME}/java/README"
	@echo ""
	@echo "and follow the directions therein."

.include <bsd.port.mk>
