# ex:ts=8
# Ports collection makefile for:	gtkwave
# Date created:			May 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gtkwave
PORTVERSION=	2.0.0.p1
PORTEPOCH=	2
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.cs.man.ac.uk/pub/amulet/gtkwave/2.0/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/pre/}

MAINTAINER=	ports@FreeBSD.org

.if !exists(/usr/bin/bzip2)
LIB_DEPENDS=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${GREP} -lR "heapsort" ${WRKSRC}/src | ${XARGS} \
		${REINPLACE_CMD} -e "s/heapsort/hsort/g"

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc ; ${INSTALL_DATA} *.png *.ps *.html ${DOCSDIR})
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples ; ${INSTALL_DATA} *.gz *.vcd ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
