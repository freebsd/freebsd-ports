# New ports collection makefile for: 	opendis
# Date created:		22 May 2001
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	opendis
PORTVERSION=	0.0.3
CATEGORIES=	graphics
MASTER_SITES=	http://ods.sourceforge.net/dl/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	ports@FreeBSD.org

USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

DOCS=	NEWS AUTHORS doc/ERRATA doc/PHILOSOPHY doc/THUMB

.if !defined(NOPORTDOCS)
post-install:
	@${INSTALL} -d -o root -g wheel -m 0755 ${PREFIX}/share/doc/${PORTNAME}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
