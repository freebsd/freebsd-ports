# New ports collection makefile for:    bytebench
# Version required:     
# Date created:         28 December 1995
# Whom:                 se
#
# $Id: Makefile,v 1.5 1996/11/18 11:21:48 asami Exp $
#

DISTNAME=       bytebench-3.1
CATEGORIES=	benchmarks
MASTER_SITES=   ftp://ftp.inria.fr/system/benchmark/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	se@FreeBSD.org

do-install:
		-${MKDIR} $(PREFIX)/lib/bytebench
		for f in Makefile README Run doc pgms results testdir; \
			do ${CP} -R $(WRKSRC)/$$f $(PREFIX)/lib/bytebench; done
		echo "#!/bin/sh"		   >  $(PREFIX)/bin/bytebench
		echo "TMPDIR=\$${TMPDIR-/var/tmp}" >> $(PREFIX)/bin/bytebench
		echo "RESULTDIR=/tmp"		   >> $(PREFIX)/bin/bytebench
		echo "export TMPDIR RESULTDIR"	   >> $(PREFIX)/bin/bytebench
		echo "cd $(PREFIX)/lib/bytebench"  >> $(PREFIX)/bin/bytebench
		echo "exec ./Run \"\$$@\""	   >> $(PREFIX)/bin/bytebench
		chmod 755 $(PREFIX)/bin/bytebench
		chmod 644 $(PREFIX)/lib/bytebench/Makefile
		chmod 644 $(PREFIX)/lib/bytebench/README
		chmod 755 $(PREFIX)/lib/bytebench/Run
		chmod 755 $(PREFIX)/lib/bytebench/doc
		chmod 755 $(PREFIX)/lib/bytebench/pgms
		chmod 755 $(PREFIX)/lib/bytebench/pgms/*
		chmod 755 $(PREFIX)/lib/bytebench/results
		chmod 755 $(PREFIX)/lib/bytebench/testdir

.include <bsd.port.mk>
