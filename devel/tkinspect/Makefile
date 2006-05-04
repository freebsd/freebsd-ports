# New ports collection makefile for: 	tkinspect
# Date created:				Dec 28 2002
# Whom:					Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

PORTNAME=	tkinspect
PORTVERSION=	5.1.6p9
CATEGORIES=	devel tcl83 tk83
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=tkcon

MAINTAINER=	nox@jelal.kn-bremen.de
COMMENT=	A Tk program browser

RUN_DEPENDS=	wish8.3:${PORTSDIR}/x11-toolkits/tk83

# this would do an interactive install:
#do-install:
#		(cd ${WRKSRC} && ./install.tcl)

post-patch:
		(cd ${WRKSRC} && ${RM} *.orig)

do-build:
		${REINPLACE_CMD} s%@tkinspect_library@%${PREFIX}/lib/tkinspect%g ${WRKSRC}/tkinspect.tcl
		${RM} ${WRKSRC}/tkinspect.tcl.bak

do-install:
		${MKDIR} ${PREFIX}/lib/tkinspect/stl-lite
		${INSTALL_SCRIPT} ${WRKSRC}/tkinspect.tcl ${PREFIX}/bin/tkinspect
		${INSTALL_DATA} `echo ${WRKSRC}/* |${SED} s%${WRKSRC}/stl-lite\ %%` ${PREFIX}/lib/tkinspect
		${INSTALL_DATA} ${WRKSRC}/stl-lite/* ${PREFIX}/lib/tkinspect/stl-lite
		(cd ${PREFIX}/lib/tkinspect && ${RM} README dot.tkinspect_init install.tcl sls.xbm stl-lite/COPYRIGHT tkinspect.tcl)

.include <bsd.port.mk>
