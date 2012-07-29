# New ports collection makefile for:	eblook
# Date created:		20 August 1999
# Whom:			Shigeyuki Fukushima <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	eblook
PORTVERSION=	1.6.1
PORTREVISION=	6
CATEGORIES=	japanese textproc
MASTER_SITES=	http://openlab.ring.gr.jp/edict/eblook/dist/
DIST_SUBDIR=	eb

MAINTAINER=	yasu@utahime.org
COMMENT=	Interactive EB interface command for searching words in electronic dictionaries

LIB_DEPENDS=	eb.15:${PORTSDIR}/japanese/eb

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-eb-includes=${PREFIX}/include \
			--with-eb-libraries=${PREFIX}/lib

INFO=		eblook

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for i in AUTHORS COPYING ChangeLog NEWS README ; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${DOCSDIR} ;\
	done
.endif

.include <bsd.port.mk>
