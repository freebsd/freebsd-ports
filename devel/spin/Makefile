# Ports collection makefile for: spin
# Date created:		Oct 23, 1997
# Whom:			jhanna@home.com
#
# $FreeBSD$
#

PORTNAME=	spin
PORTVERSION=	4.0.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://spinroot.com/spin/Src/
DISTFILES=	spin${PORTVERSION:S/.//g}.tar.gz

MAINTAINER=	jhanna@shaw.ca
COMMENT=	An on-the-fly verification system for asynchronous concurrent systems

.if !defined(WITHOUT_XSPIN)
RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84
PLIST_SUB+=	XSPIN=""
.else
PLIST_SUB+=	XSPIN="@comment "
.endif

DIST_SUBDIR=	spin
WRKSRC=		${WRKDIR}/Src${PORTVERSION}
MAKEFILE=	make_unix
ALL_TARGET=	spin
USE_REINPLACE=	yes

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Use WITHOUT_XSPIN=yes to suppress xspin (and TCL/Tk dependency)."
	@${ECHO_MSG} ""

post-extract:
	@cd ${WRKDIR}/Test && ${SH} ${WRKDIR}/Test/examples

post-patch:
	@WISH=`(cd ${LOCALBASE}/bin ; ${LS} wish8* ) | tail -1` ; \
	if [ -z "$$WISH" ] ; then WISH=wish8.0 ; fi ; \
	${REINPLACE_CMD} \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g;" \
		-e "s|%%WISH%%|$$WISH|g" ${WRKDIR}/Xspin4.0/xspin407.tcl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spin ${PREFIX}/bin
.if !defined(WITHOUT_XSPIN)
	${RM} -f ${PREFIX}/bin/xspin
	${INSTALL_SCRIPT} ${WRKDIR}/Xspin4.0/xspin407.tcl ${PREFIX}/bin/xspin
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/Doc
	${MKDIR} ${DOCSDIR}/Examples
	${MKDIR} ${DOCSDIR}/Test
	${INSTALL_DATA} ${WRKDIR}/Doc/* ${DOCSDIR}/Doc
	${INSTALL_DATA} ${WRKDIR}/Test/ex.* ${DOCSDIR}/Examples
.for i in README.tests abp eratosthenes hello leader leader.ltl leader2 \
	loops mobile1 mobile1.ltl mobile2 mobile2.ltl pathfinder peterson petersonN pftp priorities snoopy sort wordcount
	${INSTALL_DATA} ${WRKDIR}/Test/$i ${DOCSDIR}/Test
.endfor
.endif

.include <bsd.port.mk>
