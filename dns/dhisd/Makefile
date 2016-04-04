# Created by: Bas Kruit <baskruit@bsltwr.dhis.org>
# $FreeBSD$

PORTNAME=	dhisd
PORTVERSION=	5.1
PORTREVISION=	5
CATEGORIES=	dns
MASTER_SITES=	ftp://ftp.dhis.org/pub/dhis/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DHIS server for dynamic updates on the server using specific engines

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libgmp.so:math/gmp

CFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib

PORTDOCS=	CONTRIBUTORS COPYRIGHT INSTALL MODULES README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	${CP} ${FILESDIR}/dhisd.sh ${WRKSRC}/dhisd.sh
	cd ${WRKSRC} && ${REINPLACE_CMD} -e "s^__PREFIX__^${PREFIX}^g" \
		Makefile dhisd.h dhisd.sh ${PORTDOCS}

do-install:

post-install:
	@${ECHO_MSG} "===>   Installing ${STAGEDIR}${PREFIX}/sbin/dhisd."
	@${INSTALL_PROGRAM} ${WRKSRC}/dhisd ${STAGEDIR}${PREFIX}/sbin
	@${ECHO_CMD} "sbin/dhisd" >> ${TMPPLIST}
	@${ECHO_MSG} "===>   Installing ${STAGEDIR}${PREFIX}/sbin/sgenkeys."
	@${INSTALL_PROGRAM} ${WRKSRC}/genkeys ${STAGEDIR}${PREFIX}/sbin
	@${ECHO_CMD} "sbin/genkeys" >> ${TMPPLIST}
	@${ECHO_MSG} "===>   Creating ${STAGEDIR}${PREFIX}/etc/dhis and installing sample db."
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/dhis
	@${CHMOD} 700 ${STAGEDIR}${PREFIX}/etc/dhis
	@${INSTALL_DATA} ${WRKSRC}/dhis.db.sample ${STAGEDIR}${PREFIX}/etc/dhis/dhis.db.sample
	@${ECHO_CMD} "etc/dhis/dhis.db.sample" >> ${TMPPLIST}
	@${INSTALL_DATA} ${WRKSRC}/services.db.sample ${STAGEDIR}${PREFIX}/etc/dhis/services.db.sample
	@${ECHO_CMD} "etc/dhis/services.db.sample" >> ${TMPPLIST}
	@${CHMOD} 600 ${STAGEDIR}${PREFIX}/etc/dhis/*
.if !exists(${STAGEDIR}${PREFIX}/etc/rc.d/dhisd.sh)
	@${ECHO_MSG} "===>   Installing ${STAGEDIR}${PREFIX}/etc/rc.d/dhid.sh startup file."
	@${INSTALL_SCRIPT} -m 751 ${WRKSRC}/dhisd.sh ${STAGEDIR}${PREFIX}/etc/rc.d/dhisd.sh
	@${ECHO_CMD} "etc/rc.d/dhisd.sh" >> ${TMPPLIST}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "===>   Installing documentation in ${STAGEDIR}${DOCSDIR}"
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${CHMOD} 755 ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${FILESDIR}/INSTALL.bsd ${STAGEDIR}${DOCSDIR}
	@${ECHO_CMD} "share/doc/${PORTNAME}/INSTALL.bsd" >> ${TMPPLIST}
.endif
	@${ECHO} "--------------------------------------------------------------------------"
	@${ECHO} "Before dhisd can run, you will need configure BIND."
	@${ECHO} ""
	@${ECHO} "For more information, see the following site:"
	@${ECHO} "http://www.dhis.org/dhis/r5/"
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO} ""
	@${ECHO} "or the documents in ${STAGEDIR}${DOCSDIR}"
	@${ECHO} "Read INSTALL and INSTALL.bsd at least for the setup information of dhisd."
.endif
	@${ECHO} "--------------------------------------------------------------------------"

.include <bsd.port.mk>
