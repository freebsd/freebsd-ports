# New ports collection makefile for:	eblook
# Date created:		20 August 1999
# Whom:			Shigeyuki Fukushima <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	eblook
PORTVERSION=	1.5.1
PORTREVISION=	2
CATEGORIES=	japanese textproc
MASTER_SITES=	http://openlab.ring.gr.jp/edict/eblook/dist/
DIST_SUBDIR=	eb

MAINTAINER=	shige@FreeBSD.org
COMMENT=	Interactive EB interface command for seraching words in electoric dictionaries

DOCDIR=		share/doc/eblook

LIB_DEPENDS=    eb.7:${PORTSDIR}/japanese/eb

GNU_CONFIGURE=	yes
USE_AUTOMAKE=	yes
CONFIGURE_ARGS=	--with-eb-includes=${PREFIX}/include \
		--with-eb-libraries=${PREFIX}/lib

PLIST_SUB=	DOCDIR=${DOCDIR}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${DOCDIR}
	@for i in AUTHORS COPYING ChangeLog NEWS README ; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/${DOCDIR} ;\
	done
.endif

.include <bsd.port.mk>
