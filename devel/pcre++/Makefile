# ex:ts=8
# Ports collection makefile for:	pcre++
# Date created:			Jan 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pcre++
PORTVERSION=	0.6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.daemon.de/scip/Apps/pcre++/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A wrapper class around the pcre library

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

PCRE_CONFIG?=	${LOCALBASE}/bin/pcre-config

USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="`${PCRE_CONFIG} --cflags`" \
		LDFLAGS="`${PCRE_CONFIG} --libs`"
INSTALLS_SHLIB=	yes

MAN3=	Pcre.3

post-patch:
	@${REINPLACE_CMD} -e 's|-I/usr/local/include||g ; \
		 s|-L/usr/local/lib||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-O -g|\@CXXFLAGS\@|g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.* ${DOCSDIR}
.endif

.include <bsd.port.mk>
