# New ports collection makefile for:    bytebench
# Version required:    	3.1
# Date created:         28 December 1995
# Whom:                 se
#
# $Id: Makefile,v 1.8 1999/07/18 06:02:55 cpiazza Exp $
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
	${ECHO} "#!/bin/sh"		   >  $(PREFIX)/bin/bytebench
	${ECHO} "TMPDIR=\$${TMPDIR-/var/tmp}" >> $(PREFIX)/bin/bytebench
	${ECHO} "RESULTDIR=/tmp"		   >> $(PREFIX)/bin/bytebench
	${ECHO} "export TMPDIR RESULTDIR"	   >> $(PREFIX)/bin/bytebench
	${ECHO} "cd $(PREFIX)/lib/bytebench"  >> $(PREFIX)/bin/bytebench
	${ECHO} "exec ./Run \"\$$@\""	   >> $(PREFIX)/bin/bytebench
	${CHMOD} 755 $(PREFIX)/bin/bytebench
	chmod 644 $(PREFIX)/lib/bytebench/Makefile
	chmod 644 $(PREFIX)/lib/bytebench/README
	chmod 755 $(PREFIX)/lib/bytebench/Run
	chmod 755 $(PREFIX)/lib/bytebench/doc
	chmod 755 $(PREFIX)/lib/bytebench/pgms
	chmod 755 $(PREFIX)/lib/bytebench/pgms/*
	chmod 755 $(PREFIX)/lib/bytebench/results
	chmod 755 $(PREFIX)/lib/bytebench/testdir
	@rm -f ${PREFIX}/lib/bytebench/pgms/*.orig

.include <bsd.port.mk>
