# ex:ts=8
# Ports collection makefile for:	ptypes
# Date created:			Aug 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ptypes
PORTVERSION=	1.5.3
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	http://www.melikyan.com/ptypes/ \
		http://ptypes.sourceforge.net/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes

post-patch:
.for dir in src wshare
	@${REINPLACE_CMD} -e "s|-pthread|${PTHREAD_LIBS}|g" ${WRKSRC}/${dir}/Makefile.FreeBSD
.endfor

do-install:
	@${MKDIR} ${PREFIX}/include/ptypes
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include/ptypes
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libptypes.a ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/doc
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${WRKSRC}/index.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}/doc
.endif

.include <bsd.port.mk>
