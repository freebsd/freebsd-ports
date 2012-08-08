# New ports collection makefile for:	py-asn1-modules
# Date created:				20 March 2011
# Whom:					Ruslan Mahmatkhanov <cvs-src@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	asn1-modules
PORTVERSION=	0.0.4
CATEGORIES=	devel python
MASTER_SITES=	SF/pyasn1/py${PORTNAME}/${PORTVERSION} \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Collection of ASN.1 data structures for py-asn1

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1>=0.1.4:${PORTSDIR}/devel/py-asn1

# Python3 ready
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	pyasn1-modules

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

BASEDOCS=	CHANGES README

TOOLS=		cmpdump.py crldump.py crmfdump.py ocspclient.py ocspreqdump.py \
		ocsprspdump.py ocspserver.py pkcs10dump.py pkcs1dump.py \
		pkcs7dump.py pkcs8dump.py snmpget.py x509dump.py

post-install:
.for t in ${TOOLS}
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/${t} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${BASEDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
