# New ports collection makefile for:	dhisd
# Date created:				Sun Feb 25 21:13:59 CET 2001
# Whom:					Bas Kruit <baskruit@bsltwr.dhis.org>
#
# $FreeBSD$
#

PORTNAME=	dhisd
PORTVERSION=	5.1
PORTREVISION=	4
CATEGORIES=	dns
MASTER_SITES=	ftp://ftp.dhis.org/pub/dhis/

MAINTAINER=	marius@FreeBSD.org
COMMENT=	DHIS server for dynamic updates on the server using specific engines

LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

CFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib
MAKE_ENV=	LDFLAGS="${LDFLAGS}"

DOCFILES=	CONTRIBUTORS COPYRIGHT INSTALL MODULES README

post-patch:
	${CP} ${FILESDIR}/dhisd.sh ${WRKSRC}/dhisd.sh
	cd ${WRKSRC} && ${REINPLACE_CMD} -e "s^__PREFIX__^${PREFIX}^g" \
		Makefile dhisd.h dhisd.sh ${DOCFILES}

do-install:

post-install:
	@${ECHO_MSG} "===>   Installing ${PREFIX}/sbin/dhisd."
	@${INSTALL_PROGRAM} ${WRKSRC}/dhisd ${PREFIX}/sbin
	@${ECHO_CMD} "sbin/dhisd" >> ${TMPPLIST}
	@${ECHO_MSG} "===>   Installing ${PREFIX}/sbin/sgenkeys."
	@${INSTALL_PROGRAM} ${WRKSRC}/genkeys ${PREFIX}/sbin
	@${ECHO_CMD} "sbin/genkeys" >> ${TMPPLIST}
	@${ECHO_MSG} "===>   Creating ${PREFIX}/etc/dhis and installing sample db files."
	@${MKDIR} ${PREFIX}/etc/dhis
	@${CHMOD} 700 ${PREFIX}/etc/dhis
	@${INSTALL_DATA} ${WRKSRC}/dhis.db.sample ${PREFIX}/etc/dhis/dhis.db.sample
	@${ECHO_CMD} "etc/dhis/dhis.db.sample" >> ${TMPPLIST}
	@${INSTALL_DATA} ${WRKSRC}/services.db.sample ${PREFIX}/etc/dhis/services.db.sample
	@${ECHO_CMD} "etc/dhis/services.db.sample" >> ${TMPPLIST}
	@${CHMOD} 600 ${PREFIX}/etc/dhis/*
	@${ECHO_CMD} "@dirrm etc/dhis" >> ${TMPPLIST}
.if !exists(${PREFIX}/etc/rc.d/dhisd.sh)
	@${ECHO_MSG} "===>   Installing ${PREFIX}/etc/rc.d/dhid.sh startup file."
	@${INSTALL_SCRIPT} -m 751 ${WRKSRC}/dhisd.sh ${PREFIX}/etc/rc.d/dhisd.sh
	@${ECHO_CMD} "etc/rc.d/dhisd.sh" >> ${TMPPLIST}
.endif
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation in ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@${CHMOD} 755 ${DOCSDIR}
.for DOCFILE in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/${DOCFILE} ${DOCSDIR}
	@${ECHO_CMD} "share/doc/${PORTNAME}/${DOCFILE}" >> ${TMPPLIST}
.endfor
	@${INSTALL_DATA} ${FILESDIR}/INSTALL.bsd ${DOCSDIR}
	@${ECHO_CMD} "share/doc/${PORTNAME}/INSTALL.bsd" >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm share/doc/${PORTNAME}" >> ${TMPPLIST}
.endif
	@${ECHO} "--------------------------------------------------------------------------"
	@${ECHO} "Before dhisd can run, you will need configure BIND."
	@${ECHO} ""
	@${ECHO} "For more information, see the following site:"
	@${ECHO} "http://www.dhis.org/dhis/r5/"
.if !defined(NOPORTDOCS)
	@${ECHO} ""
	@${ECHO} "or the files in ${DOCSDIR}"
	@${ECHO} "Read INSTALL and INSTALL.bsd at least for the setup information of dhisd."
.endif
	@${ECHO} "--------------------------------------------------------------------------"

.include <bsd.port.mk>
