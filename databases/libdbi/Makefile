# ex:ts=8
# New ports collection makefile for:	libdbi
# Date created:			Nov 4, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libdbi
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	Database Independent Abstraction Layer for C

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=		yes

post-patch:
	@${REINPLACE_CMD} -e "s|-O20|${CFLAGS}|g" -e "s|-std=gnu99||g" \
		 ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/driver-guide
	${INSTALL_DATA} ${WRKSRC}/doc/driver-guide/*.html \
		${DOCSDIR}/driver-guide
	@${MKDIR} ${DOCSDIR}/programmers-guide
	${INSTALL_DATA} ${WRKSRC}/doc/programmers-guide/*.html \
		${DOCSDIR}/programmers-guide
.endif

.include <bsd.port.mk>
