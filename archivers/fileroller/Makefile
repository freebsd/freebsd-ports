# New ports collection makefile for:	fileroller
# Date created:				18 May 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fileroller
PORTVERSION=	1.0.1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	file-roller-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	bzip:${PORTSDIR}/archivers/bzip \
		lha:${PORTSDIR}/archivers/lha \
		rar:${PORTSDIR}/archivers/rar \
		lzop:${PORTSDIR}/archivers/lzop

USE_GNOME=	yes
GNU_CONFIGURE=	yes

DOCS=	AUTHORS COPYING NEWS README TODO

.if !defined(NOPORTDOCS)
post-install:
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
