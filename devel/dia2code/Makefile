# ex:ts=8
# New ports collection makefile for:	dia2code
# Date created:			Mar 7, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dia2code
PORTVERSION=	0.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ijliao@FreeBSD.org

LIB_DEPENDS=	xml.5:${PORTSDIR}/textproc/libxml

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

XML_CONFIG=	${LOCALBASE}/bin/xml-config
USE_GMAKE=	yes

post-patch:
	@${PERL} -pi -e "s|%%XML_CONFIG%%|${XML_CONFIG}|g" ${WRKSRC}/dia2code/Makefile.in

.include <bsd.port.mk>
