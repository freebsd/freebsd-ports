# Created by: Juergen Lock <nox@jelal.kn-bremen.de>
# $FreeBSD$

PORTNAME=	tkinspect
PORTVERSION=	5.1.6p10
PORTREVISION=	1
CATEGORIES=	devel tcl tk
MASTER_SITES=   SF/tkcon/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tk program browser

RUN_DEPENDS=	wish8.4:x11-toolkits/tk84

# this would do an interactive install:
#do-install:
#		(cd ${WRKSRC} && ./install.tcl)

post-patch:
		(cd ${WRKSRC} && ${RM} *.orig)

do-build:
		${REINPLACE_CMD} s%@tkinspect_library@%${PREFIX}/lib/tkinspect%g ${WRKSRC}/tkinspect.tcl
		${RM} ${WRKSRC}/tkinspect.tcl.bak

do-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/lib/tkinspect/stl-lite
		${INSTALL_SCRIPT} ${WRKSRC}/tkinspect.tcl \
			${STAGEDIR}${PREFIX}/bin/tkinspect
		${INSTALL_DATA} `echo ${WRKSRC}/* |${SED} s%${WRKSRC}/stl-lite\ %%` \
			${STAGEDIR}${PREFIX}/lib/tkinspect
		${INSTALL_DATA} ${WRKSRC}/stl-lite/* \
			${STAGEDIR}${PREFIX}/lib/tkinspect/stl-lite
		(cd ${STAGEDIR}${PREFIX}/lib/tkinspect && \
			${RM} README dot.tkinspect_init install.tcl sls.xbm stl-lite/COPYRIGHT tkinspect.tcl)

.include <bsd.port.mk>
