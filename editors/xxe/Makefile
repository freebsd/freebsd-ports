# New ports collection makefile for:	xxe
# Date created:		19 February 2005
# Whom:			Bill Fenner
#
# $FreeBSD$
#

PORTNAME=	xxe
PORTVERSION=	4.4.0
CATEGORIES=	editors java
MASTER_SITES=	http://www.xmlmind.net/xmleditor/_download/ \
		http://www.xmlmind.com/xmleditor/_download/
PKGNAMESUFFIX=	-perso
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A validating XML editor featuring a word processor-like view

USE_JAVA=	YES
JAVA_VERSION=	1.5+
NO_BUILD=	YES

#RESTRICTED=	"Licensee may not distribute the Software"

BINS=		convertdoc csscheck deploywebstart dtdtoxsd dtdvalid \
		rngvalid schvalid xsdvalid xxe

PLIST_SUB=	XXE=${DISTNAME}

post-extract:
		@${SED} -e 's,%%JAVA_HOME%%,${JAVA_HOME},' \
			-e 's,%%PREFIX%%,${PREFIX},' \
			-e 's,%%DISTNAME%%,${DISTNAME},' \
			${FILESDIR}/launcher > ${WRKDIR}/xxe

do-install:
		@cd ${WRKDIR} && tar cf - ${DISTNAME} | \
				 tar -C ${PREFIX}/lib -xf -
.for f in ${BINS}
		@${INSTALL_SCRIPT} ${WRKDIR}/xxe ${PREFIX}/bin/${f}
.endfor

.include <bsd.port.mk>
