# New ports collection makefile for:	kakasi
# Date created:			26 Mar. 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kakasi
PORTVERSION=	2.3.3
CATEGORIES=	japanese
MASTER_SITES=	ftp://kakasi.namazu.org/pub/kakasi/stable/

MAINTAINER=	max@FreeBSD.org

GNU_CONFIGURE=	yes

MANLANG=		ja
MAN1=			kakasi.1
INSTALLS_SHLIB=	yes

DOCS=		ChangeLog.lib JISYO README.BeOS README.OS2 README.lib \
		README.wakati kakasi.1 kakasi.cat

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/kakasi.1 ${PREFIX}/man/${MANLANG}/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/kakasi
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/$f ${PREFIX}/share/doc/kakasi
.endfor
.endif

.include <bsd.port.mk>
