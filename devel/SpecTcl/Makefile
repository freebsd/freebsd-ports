# New ports collection makefile for:	SpecTcl1.1
# Date created:		Fri Oct  3 18:50:53 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	SpecTcl
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	devel tk
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free drag-and-drop GUI builder for Tk and Java from Sun

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

NO_BUILD=	yes

WISH=		${LOCALBASE}/bin/wish8.4

post-patch:
.for file in specJava specTcl
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
		 s|%%WISH%%|${WISH}|g' ${WRKSRC}/bin/${file}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/specJava ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/specTcl ${PREFIX}/bin
	${MKDIR} ${PREFIX}/SpecTcl
	${INSTALL_DATA} ${WRKSRC}/changes ${PREFIX}/SpecTcl
	${INSTALL_DATA} ${WRKSRC}/license.terms ${PREFIX}/SpecTcl
	${MKDIR} ${PREFIX}/SpecTcl/lib
	${CP} -r ${WRKSRC}/SpecTcl/* ${PREFIX}/SpecTcl/lib
	${MKDIR} ${PREFIX}/SpecTcl/demo
	${CP} -r ${WRKSRC}/demo/* ${PREFIX}/SpecTcl/demo
	${MKDIR} ${PREFIX}/SpecTcl/examples
	${CP} -r ${WRKSRC}/examples/* ${PREFIX}/SpecTcl/examples

.include <bsd.port.mk>
