# New ports collection makefile for:	NetRexx
# Date created:		Feb 8, 1999
# Whom:			Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	NetRexx
PORTVERSION=	2.02
CATEGORIES=	java lang
MASTER_SITES=	http://www2.hursley.ibm.com/netrexx/
DISTNAME=	NetRexx

MAINTAINER=	jmcoopr@webmail.bmi.net

RUN_DEPENDS=	${LOCALBASE}/jdk1.1.8/bin/java:${PORTSDIR}/java/jdk \
		${LOCALBASE}/bin/rexx:${PORTSDIR}/lang/rexx-imc

NO_BUILD=	yes
USE_ZIP=	yes

pre-patch:
	@${PERL} -pi -e 's///' ${WRKSRC}/bin/NetRexxC.sh

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/NetRexxC.sh ${PREFIX}/bin
	@${LN} -sf ${PREFIX}/bin/NetRexxC.sh ${PREFIX}/bin/nrc
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/NetRexxC.cmd \
		${PREFIX}/bin/NetRexxC.rexx
	@${LN} -sf ${PREFIX}/bin/NetRexxC.rexx ${PREFIX}/bin/nrc.rexx

	@${MKDIR} ${PREFIX}/NetRexx/lib
	@${INSTALL_DATA} ${WRKSRC}/lib/NetRexxC.jar ${PREFIX}/NetRexx/lib/
	@${INSTALL_DATA} ${WRKSRC}/runlib/NetRexxR.jar ${PREFIX}/NetRexx/lib/

	@${MKDIR} ${PREFIX}/share/examples/NetRexx
	@${INSTALL_DATA} ${WRKSRC}/bin/hello.nrx \
		${PREFIX}/share/examples/NetRexx/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/netrexx/lang
.for dir in netrexx/lang .
	@${INSTALL_DATA} ${WRKSRC}/browse/${dir}/* ${DOCSDIR}/${dir}
	@${RM} -Rf ${WRKSRC}/browse/netrexx
.endfor
.endif

post-install:
	@${ECHO} "====================  IBM LICENSE  ===================="
	@${CAT} ${WRKSRC}/browse/license.txt
	@${ECHO} "-------------------------------------------------------"
	@${ECHO} "====================  IMPORTANT!!  ===================="
	@${CAT} ${WRKSRC}/read.me.first

.include <bsd.port.mk>
