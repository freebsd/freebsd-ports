# New ports collection makefile for: ilu
# Version required:     2.0alpha11
# Date created:         29.9.1997
# Whom:                 cracauer@cons.org "Martin Cracauer"
#
# $Id: Makefile,v 1.1.1.1 1997/10/01 08:12:53 cracauer Exp $
#

DISTNAME=       ilu-2.0alpha11
PKGNAME=	ilu-2.0a11
CATEGORIES=     devel
MASTER_SITES=   ftp://parcftp.xerox.com/pub/ilu/2.0a11/

MAINTAINER=	cracauer@cons.org

NO_WRKSUBDIR=   yes
HAS_CONFIGURE=	yes
# ILU 2.0alpha11 doesn't compile with FreeBSD jdk-1.1 port
CONFIGURE_ARGS= --disable-java-support --enable-http-protocol

PKGDIR=		var-pkg

INSTALL_TARGET=	Install
NOMANCOMPRESS=

post-install:
	# Empty dirs
	${RMDIR} ${PREFIX}/ilu/man/man[358]
	${RMDIR} ${PREFIX}/ilu/lisp
.if !exists(var-pkg)
	${MKDIR} var-pkg
.endif
	${CP} pkg/COMMENT var-pkg/.
	${CP} pkg/DESCR var-pkg/.
	(cd ${PREFIX} ; find ilu -type f) > var-pkg/PLIST
	(cd ${PREFIX} ; find ilu -type d) | ${AWK} '{print "@dirrm " $$1}' \
		| tail -r >> var-pkg/PLIST
	(cd ${PREFIX}/ilu/bin ; for file in * ; do \
		ln -fs ${PREFIX}/ilu/bin/$$file ${PREFIX}/bin/. ; \
		${ECHO} @exec ln -fs %D/ilu/bin/$$file %D/bin/. ; \
		${ECHO} @unexec ${RM} %D/bin/$$file ; \
		done) >> var-pkg/PLIST
	(cd ${PREFIX}/ilu/man/man1 ; for file in * ; do \
		ln -fs ${PREFIX}/ilu/man/man1/$$file ${PREFIX}/man/man1/. ; \
		${ECHO} @exec ln -fs %D/ilu/man/man1/$$file %D/man/man1/. ; \
		${ECHO} @unexec ${RM} %D/man/man1/$$file ; \
		done) >> var-pkg/PLIST
	# Empty dir, but we really need it
	${ECHO} @exec ${MKDIR} %D/ilu/lib/binding >> var-pkg/PLIST
	${ECHO} @exec chmod 777 %D/ilu/lib/binding >> var-pkg/PLIST

.include <bsd.port.mk>
