# ex:ts=8
# New ports collection makefile for:	dia2code
# Date created:			Mar 7, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dia2code
PORTVERSION=	0.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2 \
		giconv:${PORTSDIR}/converters/libiconv

GNU_CONFIGURE=	yes
XML_CONFIG=	${LOCALBASE}/bin/xml2-config
USE_GMAKE=	yes

post-patch:
	@${PERL} -pi -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/dia2code/Makefile.in
	@${PERL} -pi -e "s|malloc.h|stdlib.h|g" ${WRKSRC}/dia2code/dia2code.h

.include <bsd.port.mk>
