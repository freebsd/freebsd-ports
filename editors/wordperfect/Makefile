# ports collection makefile for:	wordperfect
# Version required:			8.0
# Date created:				1998-Dec-10
# Whom:					dugsong@OpenBSD.ORG
#					msmith@freebsd.org
# Relevant URLs:			http://www.corel.com/
#
# $Id$

DISTNAME=	GUILG00
PKGNAME=	wordperfect-8.0
CATEGORIES=     editors
MASTER_SITES=	"Fetch must be performed manually"
EXTRACT_SUFX=	.GZ

MAINTAINER=	msmith@freebsd.org

RUN_DEPENDS=    /compat/linux/lib/libc.so.5:${PORTSDIR}/emulators/linux_lib

NO_CDROM=	"LIC: redistribution not allowed"

IS_INTERACTIVE=	"requires user interaction for installation"

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTFILES} ]; then \
	   ${ECHO} "" ; \
	   ${ECHO} "  The source to this port may not be automatically fetched" ; \
	   ${ECHO} "  due to licensing restrictions. You MUST fetch the source" ; \
	   ${ECHO} "  manually after reading and agreeing to the license at:" ; \
	   ${ECHO} "" ; \
	   ${ECHO} "      http://linux.corel.com/linux8/download.htm" ; \
	   ${ECHO} "" ; \
	   ${ECHO} "  Once ${DISTFILES} has been downloaded, move it to ${DISTDIR}" ; \
	   ${ECHO} "  and then restart this build." ; \
	   ${ECHO} "" ; \
	   exit 1 ; \
	fi

post-extract:
	@(cd ${WRKDIR} ; for file in b* g* ; do ${EXTRACT_CMD} -xf $$file ; done)

post-patch:
	@${CP} ${WRKDIR}/shared/wpdata ${WRKDIR}/shared/wpdata.old
	@${SED} 's#idir=#idir=${PREFIX}/lib/corel#' \
		< ${WRKDIR}/shared/wpdata.old \
		> ${WRKDIR}/shared/wpdata
	@${CP} ${WRKDIR}/shared/install.wp ${WRKDIR}/shared/install.wp.old
	@sed 's#REPLACE_ME_WITH_DESTINATION#${PREFIX}/lib/corel#' \
		< ${WRKDIR}/shared/install.wp.old \
		> ${WRKDIR}/shared/install.wp

pre-install:
	@${ECHO} "" ; \
	${ECHO} "   This installation of WordPerfect will expire in 90 days," ; \
	${ECHO} "   unless you retrieve a free registration key from" ; \
	${ECHO} "" ; \
	${ECHO} "         https://livewire.corel.com/wp8LinuxReg/" ; \
	${ECHO} "" ; \
	${ECHO} "   to register your copy TODAY. Do this now!" ; \
	${ECHO} "" ; \
	${ECHO} "   The installation default directory ${PREFIX}/lib/corel must be" ; \
	${ECHO} "   accepted for installation to proceed correctly.  If the installation" ; \
	${ECHO} "   needs to be relocated, set PREFIX and restart the installation." ; \

do-install:
	@${MKDIR} ${WRKDIR}/tmp
	@(cd ${WRKDIR} ; ${SCRIPTS_ENV} TMPDIR=${WRKDIR}/tmp ${SH} Runme)
	@sed 's#REPLACE_ME_WITH_DESTINATION#${PREFIX}/lib/corel#' \
		< ${FILESDIR}/xwp \
		> ${WRKDIR}/xwp
	@if test -f ${PREFIX}/bin/xwp ; then \
	   ${MV} ${PREFIX}/bin/xwp ${PREFIX}/bin/xwp.old ; fi
	@${INSTALL_SCRIPT} ${WRKDIR}/xwp ${PREFIX}/bin

.include <bsd.port.mk>
