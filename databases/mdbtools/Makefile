# New ports collection makefile for:	mdbtools
# Date created:				25 April 2001
# Whom:	      				Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	mdbtools
PORTVERSION=	0.3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.nuug.no/pub/anders/distfiles/ \
		http://www.freenix.no/~anders/
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@fix.no

USE_GLIB=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS+=	GLIB_CONFIG="${GLIB_CONFIG}"
INSTALLS_SHLIB=	yes

DOCS=		AUTHORS ChangeLog HACKING NEWS README TODO INSTALL

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f}  ${PREFIX}/share/doc/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
