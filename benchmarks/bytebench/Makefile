# New ports collection makefile for:    bytebench
# Date created:         28 December 1995
# Whom:                 se
#
# $FreeBSD$
#

PORTNAME=	bytebench
PORTVERSION=	3.1
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.inria.fr/system/benchmark/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	se@FreeBSD.org

do-install:
	-${MKDIR} $(PREFIX)/lib/bytebench
	for f in Makefile README Run doc pgms results testdir; \
		do ${CP} -R $(WRKSRC)/$$f $(PREFIX)/lib/bytebench; done
	${ECHO_CMD} "#!/bin/sh"		   >  $(PREFIX)/bin/bytebench
	${ECHO_CMD} "TMPDIR=\$${TMPDIR-/var/tmp}" >> $(PREFIX)/bin/bytebench
	${ECHO_CMD} "RESULTDIR=/tmp"		   >> $(PREFIX)/bin/bytebench
	${ECHO_CMD} "export TMPDIR RESULTDIR"	   >> $(PREFIX)/bin/bytebench
	${ECHO_CMD} "cd $(PREFIX)/lib/bytebench"  >> $(PREFIX)/bin/bytebench
	${ECHO_CMD} "exec ./Run \"\$$@\""	   >> $(PREFIX)/bin/bytebench
	${CHMOD} 755 $(PREFIX)/bin/bytebench
	${CHMOD} 644 $(PREFIX)/lib/bytebench/Makefile
	${CHMOD} 644 $(PREFIX)/lib/bytebench/README
	${CHMOD} 755 $(PREFIX)/lib/bytebench/Run
	${CHMOD} 755 $(PREFIX)/lib/bytebench/doc
	${CHMOD} 755 $(PREFIX)/lib/bytebench/pgms
	${CHMOD} 755 $(PREFIX)/lib/bytebench/pgms/*
	${CHMOD} 755 $(PREFIX)/lib/bytebench/results
	${CHMOD} 755 $(PREFIX)/lib/bytebench/testdir
	@${RM} -f ${PREFIX}/lib/bytebench/pgms/*.orig

.include <bsd.port.mk>
