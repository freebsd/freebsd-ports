# Ports collection makefile for:	Poseidon
# Date created:			February 28, 2004
# Whom:				Gerrit Beine (<tux@pinguru.net>)
#
# $FreeBSD$
#

PORTNAME=	poseidon
PORTVERSION=	2.5.0
CATEGORIES=	java
MASTER_SITES=	ftp://ftp.gentleware.org/
DISTNAME=	${PORTNAME}${EDI}-${PORTVERSION}

MAINTAINER=	tux@pinguru.net
COMMENT=	A popular UML CASE tool

USE_ZIP=	yes
USE_JAVA=	1.4+
USE_REINPLACE=	yes
NO_BUILD=	yes
NO_PACKAGE=	"Redistribution is not permitted"
NO_CDROM=	${NO_PACKAGE}
RESTRICTED=	${NO_PACKAGE}

.for edition in SE PE
. if defined(POSEIDON_${edition})
EDI=	${edition}
. endif
.endfor
.if !defined(EDI)
EDI=	CE
.endif
PKGLIST=	pkg-plist.${EDI}
.if (${EDI} != PE)
POSEIDON_PATCH=	${PORTNAME}${EDI}.sh.patch
.endif

PLIST:=		${WRKSRC}/PLIST

pre-fetch:
	@${ECHO_MSG}
	@${ECHO_MSG} "There is a free usable edition of Poseidon for UML,"
	@${ECHO_MSG} "the Community Edition, which is installed by default."
	@${ECHO_MSG}
	@${ECHO_MSG} "If you like to install the Standard Edition or the Professional Edition"
	@${ECHO_MSG} "please specify POSEIDON_SE=yes for the Standard Edition"
	@${ECHO_MSG} "or POSEIDON_PE=yes for the Professional Edition."
	@${ECHO_MSG}

post-patch:
.if(defined(POSEIDON_PATCH))
	@cd ${WRKSRC} && ${PATCH} < ${PATCHDIR}/${POSEIDON_PATCH}
.endif
	@${REINPLACE_CMD} -e "s,%%JAVA_HOME%%,${JAVA_HOME}," ${WRKSRC}/bin/poseidon.sh

pre-install:
	@${CAT} ${PKGLIST} ${PKGDIR}/pkg-plist > ${PLIST}

do-install:
	@${MKDIR} ${DATADIR}/bin
	@${MKDIR} ${DATADIR}/lib
.if(defined(POSEIDON_PE))
	@${MKDIR} ${DATADIR}/lib/templates
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/bin/poseidon.sh ${DATADIR}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${DATADIR}/lib
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${DATADIR}
.if(defined(POSEIDON_PE))
	${INSTALL_DATA} ${WRKSRC}/LICENSE-concurrent.txt ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/templates/* ${DATADIR}/lib/templates
	${INSTALL_DATA} ${WRKSRC}/lib/templates.zip ${DATADIR}/lib
.endif
.if(!defined(POSEIDON_SE) && !defined(POSEIDON_PE))
	${INSTALL_DATA} ${WRKSRC}/license-keys.txt ${DATADIR}
.endif
.if !defined(NOPORTDOCS)
	${CP} -r ${WRKSRC}/docs ${DATADIR}
	${CP} -r ${WRKSRC}/examples ${DATADIR}
.endif

post-install:
	${LN} -s ${DATADIR}/bin/poseidon.sh ${LOCALBASE}/bin/poseidon

.include <bsd.port.mk>
