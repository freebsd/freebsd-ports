# New ports collection makefile for:	tkp4
# Date created:         17 May 2002
# Whom:                 mi@aldan.algebra.com
#
# $FreeBSD$
#

PORTNAME=	tkp4
PORTVERSION=	1.12
CATEGORIES=	devel tk83
MASTER_SITES=	http://www.cuug.ab.ca/~macdonal/tkp4/

MAINTAINER=	mi@aldan.algebra.com

RUN_DEPENDS=	wish8.3:${PORTSDIR}/x11-toolkits/tk83

NO_BUILD=	yes

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.tcl ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tkp4 ${PREFIX}/bin
.ifndef NOPORTDOCS
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/[A-Z]* ${DOCSDIR}
.else

PKGNAMESUFFIX=	-nodocs
.endif

.include <bsd.port.pre.mk>

post-patch:
	${PERL} -pi -e 's|wish|wish8.3|' ${WRKSRC}/tkp4
.if defined(PREFIX) && ${PREFIX} != "/usr/local"
	${PERL} -pi -e 's|/usr/local|${PREFIX}|g' `${GREP} -Fl /usr/local ${WRKSRC}/*`
.endif

.include <bsd.port.post.mk>

SCRIPTS	!=	d=${DATADIR}; p=${PREFIX}; echo $${d\#\#$${p%%/}/}
DOCS	!=	d=${DOCSDIR}; p=${PREFIX}; echo $${d\#\#$${p%%/}/}
PLIST_SUB+=	SCRIPTS=${SCRIPTS} DOCS=${DOCS}
