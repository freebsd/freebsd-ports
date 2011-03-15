# ex:ts=8
# Ports collection makefile for:	fig2pstricks
# Date created:			Mar 4, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fig2pstricks
PORTVERSION=	0.7.1
CATEGORIES=	graphics
MASTER_SITES=	http://homes.eco.auckland.ac.nz/chan079/fig2pstricks/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert xfig to pstricks

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_GMAKE=	yes

PLIST_FILES=	bin/fig2pstricks

CFLAGS+=	-DVERSION=\\\"${PORTVERSION}\\\"

.if defined(WITH_LATEX)
RUN_DEPENDS+=	dvips:${PORTSDIR}/print/dvipsk-tetex \
		epstopdf:${PORTSDIR}/print/teTeX-base
USE_GHOSTSCRIPT_RUN=	yes
PLIST_FILES+=	bin/fig2epspdf
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|$$(CC)|g ; \
		 s|^CFLAGS|#CFLAGS|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if defined(WITH_LATEX)
	${INSTALL_SCRIPT} ${WRKSRC}/fig2epspdf ${PREFIX}/bin
.endif

.include <bsd.port.mk>
