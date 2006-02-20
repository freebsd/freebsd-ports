# New ports collection makefile for:	xxe
# Date created:		19 February 2005
# Whom:			Bill Fenner
#
# $FreeBSD$
#

PORTNAME=	xxe
PORTVERSION=	3.0p1
CATEGORIES=	editors java
MASTER_SITES=	http://www.xmlmind.net/xmleditor/_download/
PKGNAMESUFFIX=	-std
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION:S/.//g}

MAINTAINER=	fenner@FreeBSD.Org
COMMENT=	A validating XML editor featuring a word processor-like view

BROKEN=		Unfetchable

USE_JAVA=	YES
JAVA_VERSION=	1.5
NO_BUILD=	YES

RESTRICTED=	"Licensee may not distribute the Software"

BINS=		convertdoc csscheck deploywebstart dtdtoxsd dtdvalid \
		xsdvalid xxe

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
