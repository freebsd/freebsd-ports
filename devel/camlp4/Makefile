# New ports collection makefile for:   camlp4
# Date created:        12 July 2000
# Whom:                Kim Scarborough <user@unknown.nu>
#
# $FreeBSD$
#

PORTNAME=	camlp4
PORTVERSION=	3.06
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/cristal/camlp4/ \
		http://cristal.inria.fr/~ddr/Camlp4/ftp/ \
		http://www.unknown.nu/ports/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DOCFILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}-manual.html${EXTRACT_SUFX} \
	      	${DISTNAME}-tutorial.html${EXTRACT_SUFX}

MAINTAINER=	user@unknown.nu
COMMENT=	Pre-Processor-Pretty-Printer for Objective Caml

BUILD_DEPENDS=	ocamlc.opt:${PORTSDIR}/lang/ocaml

HAS_CONFIGURE=	yes
ALL_TARGET=	world bootstrap opt

MAN1=		camlp4.1
MLINKS=		camlp4.1 camlp4o.1 camlp4.1 camlp4o.opt.1 \
		camlp4.1 camlp4r.1 camlp4.1 camlp4r.opt.1 \
		camlp4.1 mkcamlp4.1 camlp4.1 ocpp.1

CONFIGURE_ARGS=	--prefix ${PREFIX}

BROKEN=		"Does not compile"

.if !defined(NOPORTDOCS)
DOCFILES=	${DISTNAME}-manual.html${EXTRACT_SUFX} ${DISTNAME}-manual.ps.gz \
	  	${DISTNAME}-tutorial.html${EXTRACT_SUFX} ${DISTNAME}-tutorial.ps.gz
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html/manual/lib
	@${MKDIR} ${DOCSDIR}/html/tutorial
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}-manual.html/lib/* ${DOCSDIR}/html/manual/lib/
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}-manual.html/[c-im-p]* ${DOCSDIR}/html/manual/
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}-tutorial.html/* ${DOCSDIR}/html/tutorial/
	@${INSTALL_DATA} ${DISTDIR}/${DISTNAME}-manual.ps.gz ${DOCSDIR}/
	@${INSTALL_DATA} ${DISTDIR}/${DISTNAME}-tutorial.ps.gz ${DOCSDIR}/
.endif

.include <bsd.port.mk>
