# New ports collection makefile for:	kakasi
# Date created:			26 Mar. 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kakasi
PORTVERSION=	2.3.4
CATEGORIES=	japanese textproc
MASTER_SITES=	http://kakasi.namazu.org/stable/

MAINTAINER=	ota@j.email.ne.jp
COMMENT=	Kanji-Kana Simple Inverter, language filter for Japanese

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes

MANLANG=	ja
MAN1=		kakasi.1
USE_LDCONFIG=	yes

DOCS=		NEWS README README-ja TODO \
		doc/ChangeLog.lib doc/JISYO \
		doc/README.lib doc/README.wakati

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/kakasi.1 ${PREFIX}/man/${MANLANG}/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
