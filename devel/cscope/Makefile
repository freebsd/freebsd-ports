# ports collection makefile for:	cscope
# Version required:	13.7
# Date created:		1998-11-21
# Whom:			Castor Fu
#
# $FreeBSD$
#

DISTNAME=	cscope-13.7
CATEGORIES=	devel

MAINTAINER=	castor@alumni.caltech.edu

NO_WRKSUBDIR=yes
NO_CHECKSUM=yes
RESTRICTED="Redistribution license from Lucent Technologies required."
MAKEFILE=makefile

# Location of the Cscope sources as distributed on Toolchest disk
CDROMDIR=/cdrom/cscope
TESTFILE=cscope.1

MAN1=	cscope.1

TRUNCATED_NAMES=fixkeypad.c constants.h

do-fetch:
	@${DO_NADA}

#
# Introduce the ability to get things from a fixed distribution filesystem.
#
pre-extract:
	@${MKDIR} ${_DISTDIR}
	@(cd ${_DISTDIR}; \
	 for file in ${DISTFILES}; do \
		if [ ! -f $$file -a ! -f `${BASENAME} $$file` ]; then \
			if [ -h $$file -o -h `${BASENAME} $$file` ]; then \
				${ECHO_MSG} ">> ${_DISTDIR}/$$file is a broken symlink."; \
				${ECHO_MSG} ">> Perhaps a filesystem (most likely a CD) isn't mounted?"; \
				${ECHO_MSG} ">> Please correct this problem and try again."; \
				exit 1; \
			fi ; \
			${ECHO_MSG} ">> $$file doesn't seem to exist on this system."; \
			if [ ! -d ${CDROMDIR} -a ! -f ${CDROMDIR}/${TESTFILE} ] ; then \
				${ECHO_MSG} ">> ${CDROMDIR}/${TESTFILE} not found.  Perhaps the AT&T CD isn't mounted?"; \
				${ECHO_MSG} ">> See <http://www.lucent.com/ssg/html/toolchest.html>."; \
				exit 1; \
			else \
				(cd ${CDROMDIR}; tar czf ${_DISTDIR}/$$file .); \
			fi; \
		fi \
	 done)

#
# Get rid of any <CR>'s in the files and expand out file names which may have been truncated.
#

post-extract:
	@(${CHMOD} +w ${WRKSRC})
	@(for file in ${WRKSRC}/* ; do ${TR} -d '\015' < $$file > $$file.x ; ${MV} -f $$file.x $$file ; done)
	@(for file in ${TRUNCATED_NAMES} ; do \
		x=`${ECHO} $$file | ${SED} -e 's/^\(......\).*/\1/'` ; \
		y=$${file#*.} ; \
		${MV} ${WRKSRC}/$${x}*.$${y} ${WRKSRC}/$$file; \
	done)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cscope ${PREFIX}/bin
	${INSTALL_MAN}	${WRKSRC}/cscope.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
