# New ports collection makefile for:    bytebench
# Version required:     
# Date created:         28 December 1995
# Whom:                 se
#
# $Id: Makefile,v 1.1.1.1 1996/01/01 22:57:36 se Exp $
#

DISTNAME=       bytebench-3.1
EXTRACT_SUFX=	.tar.Z
CATEGORIES+=	benchmarks
MASTER_SITES=   ftp://ftp.inria.fr/system/benchmark/

MAINTAINER=	se@FreeBSD.org

do-install:
		-mkdir -p $(PREFIX)/lib/bytebench
		for f in Makefile README Run doc pgms results testdir; \
			do cp -R $(WRKSRC)/$$f $(PREFIX)/lib/bytebench; done
		echo "!#/bin/sh"		   >  $(PREFIX)/bin/bytebench
		echo "$(PREFIX)/lib/bytebench/Run" >> $(PREFIX)/bin/bytebench
		chmod 755 $(PREFIX)/bin/bytebench

.include <bsd.port.mk>
